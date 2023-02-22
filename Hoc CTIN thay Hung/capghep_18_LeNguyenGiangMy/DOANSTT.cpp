#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef pair<int,int> ii;
const int maxn = 100;
int g[maxn][maxn], b[maxn], ptd[maxn],n;
bool mark[maxn];
struct kieu{
	int xmin, xmax, ymin, ymax;
}p[100];

bool dfs(int u){
	for(int v = 0; v < n; v++)
	if(g[u][v] && !mark[v]){
		mark[v]=1;
		if(b[v]==-1 || dfs(b[v])){
			b[v]=u;
			return 1;
		}
	} return 0;
}
int lgh(){
	int res=0;
	memset(b,-1,sizeof(b));
	for(int u=0;u<n;u++){
		memset(mark,0,sizeof(mark));
		if(dfs(u)) res++;
	} return res;
}

bool check(ii &u, kieu &v){
	return (u.fi > v.xmin) && (u.fi < v.xmax) && (u.se > v.ymin) && (u.se < v.ymax);
}

signed main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("DOANSTT.INP","r",stdin);
    freopen("DOANSTT.OUT","w",stdout);
	int tttt = 1;
	while(cin>>n,n!=0){
		memset(g,0,sizeof(g));ii t;
		for(int i=0;i<n;i++) cin>>p[i].xmin>>p[i].xmax>>p[i].ymin>>p[i].ymax;
		for(int i=0;i<n;i++){
			cin>>t.fi>>t.se;
			for(int j=0;j<n;j++)
			if(check(t,p[j])) g[i][j]=1;
		} cout<<"Heap "<<tttt++<<"\n";
		int ans=lgh();
		if(ans!=n){
			cout<<("none\n");
			continue;
		}bool kt=0;memcpy(ptd,b,sizeof(ptd));
		for(int i = 0; i < n; i++){
			g[ptd[i]][i] = 0;
			if(ans != lgh()){
			    cout<<"("<<(char)(i+65)<<","<<ptd[i] + 1<<")";
				kt = 1;
			}g[ptd[i]][i] = 1;
		} if(!kt) cout<<("none\n");
		else cout<<("\n");
		cout<<"\n";
	}return 0;
}
