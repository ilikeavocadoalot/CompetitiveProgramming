#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 1e9+7
#define	maxN 500

using namespace std;

int n,u,v,w,m,s,t,dem;
vector<int> a[1000];
int c[maxN][maxN],trace[maxN],f[maxN][maxN];

bool FindPath()
{
    memset(trace,0,sizeof(trace));
    queue<int> Q; Q.push(s); trace[s]= n+1;
    while (!Q.empty())
    {
        int u=Q.front(); Q.pop();
        for (int v=1;v<=n;v++)
			if (!trace[v]&&c[u][v]>f[u][v]){
				trace[v]=u;
				if (v==t) return true;
				Q.push(v);
			}
    }
    return false;
}

void IncFlow()
{
    int delta,u,v; dem++;
	delta=inf; v=t;
    do{
        u=trace[v];
        delta=min(delta,c[u][v]-f[u][v]);
        a[dem].push_back(u);
        v=u;
    } while (v!=s);
	v=t;
    do{
        u=trace[v];
        f[u][v]+=delta;
		f[v][u]-=delta;
        v=u;
    } while (v!=s);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("laptrinh.inp","r",stdin);
    freopen("laptrinh.out","w",stdout);
    cin>>m; s=(int)'A' - 64; n=t=(int)'Z' - 64;
    for (int i=0;i<m;i++){
        char a,b;
        cin>>a>>b>>w;
        u=(int)a -64; v=(int)b - 64;
        c[u][v]+=w;
    } while (FindPath())
            IncFlow();
    long long maxflow=0;
    for (int i=1;i<=dem;i++){
        long long tam=0;
        for (int j=1;j<(int)a[i].size();j++){
            tam+=abs(f[a[i][j-1]][a[i][j]]);
        }
        maxflow=max(maxflow,tam);
    }
    cout<<maxflow;
    return 0;
}
