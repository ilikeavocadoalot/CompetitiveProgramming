#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxN 10001
#define inf 1e9

typedef pair<int,int> ii;
typedef vector<ii> vii;
vii adj[maxN];
bool mark[maxN];
int d[maxN],parent[maxN];
int n,m,u,v,w,s,ma;

void dijkstra(int s)
{
    for(int i=1; i<=n; i++)
    {
        d[i]=inf; mark[u]=false;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[s]=0;
    pq.push(ii(0,s));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if (mark[u]) continue;
		mark[u]=true;
        for(int i=0; i<(int)adj[u].size(); i++){
            int v=adj[u][i].first;
			int w=adj[u][i].second;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                parent[v]=u;
                pq.push(ii(d[v],v));
            }
        }

    }
}
int main(){
	freopen("minpath.inp","r",stdin);
	freopen("minpath.out","w",stdout);
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(ii(v,w));
	}
    dijkstra(s);
    for (int i=1; i<=n; i++)
        if (d[i]>ma)
        {
            cout<<d[i];
            ma=d[i];
        }
    cout<<ma*2;
	return 0;
}
