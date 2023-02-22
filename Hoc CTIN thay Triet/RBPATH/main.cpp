#include <bits/stdc++.h>
using namespace std;
int n,m,b,t[100000],d[100000],ch[100000],pa[100000];
typedef pair <int,int> ii;
vector <ii> a[100000];
priority_queue <ii, vector<ii>, greater<ii>> pq;
void dijkstra ()
{
    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if (ch[u]==1) continue;
        ch[u]=1;
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
    freopen("RBPATH.INP","r",stdin);
    freopen("RBPATH.OUT","w",stdout);
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int t1,t2,we;
        cin>>t1>>t2>>we;
        a[t1].push_back(ii(t2,we));
        a[t2].push_back(ii(t1,we));
    }
    cin>>b;
    for (int i=1; i<=b; i++)
        cin>>t[i];
    for (int i=1; i<=n; i++)
    {
        d[i]=999999;
        ch[i]=0;
    }
    for (int i=1; i<=b; i++)
    {
        d[t[i]]=0;
        pq.push(ii(0,t[i]));
    }
    dijkstra();
    for (int i=1; i<=n; i++)
        cout<<d[i]<<"\n";
    return 0;
}
