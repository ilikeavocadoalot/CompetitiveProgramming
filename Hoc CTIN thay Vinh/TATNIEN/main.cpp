#include <bits/stdc++.h>
#include <queue>
using namespace std;
int pa[10000],d[10000],b[10000];
int di,n,m,t1,t2,we,ma=-999999;
typedef pair <int,int> ii;
vector <ii> a[10000];
void dijkstra (int s)
{
    for (int i=1; i<=n; i++)
    {
        d[i]=999999;
        b[i]=0;
    }
    d[s]=0;
    priority_queue <ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0,s));
    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if (b[u]==1) continue;
        b[u]=1;
        for (int i=0; i<(int)a[u].size(); i++)
        {
            int v=a[u][i].first;
            int w=a[u][i].second;
            if (d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pa[v]=u;
                pq.push(ii(d[v],v));
            }
        }

    }
}
int main()
{
    freopen("TATNIEN.INP","r",stdin);
    freopen("TATNIEN.OUT","w",stdout);
    cin>>n>>m>>di;
    for (int i=1; i<=m; i++)
    {
        cin>>t1>>t2>>we;
        a[t1].push_back(ii(t2,we));
        a[t2].push_back(ii(t1,we));
    }
    dijkstra(di);
    for (int i=1; i<=n; i++)
        if (d[i]>ma) ma=d[i];
    cout<<ma*2;
    return 0;
}
