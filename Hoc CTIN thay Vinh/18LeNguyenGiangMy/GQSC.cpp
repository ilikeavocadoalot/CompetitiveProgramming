#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 1e9+7
#define	maxN 500

using namespace std;

int n,u,v,w,m,s,t;
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
    int delta,u,v;
	delta=inf; v=t;
    do{
        u=trace[v];
        delta=min(delta,c[u][v]-f[u][v]);
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
    freopen("GQSC.inp","r",stdin);
    freopen("GQSC.out","w",stdout);
    cin>>n>>m; s=1; t=n;
    for (int i=0;i<m;i++){
        cin>>u>>v>>w;
        c[u][v]+=w;
    } while (FindPath())
            IncFlow();
    int maxflow=0;
    for (int i=1;i<=n;i++)
		if (f[s][i]>0) maxflow+=f[s][i];
    cout<<maxflow;
    return 0;
}
