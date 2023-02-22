#include <bits/stdc++.h>
using namespace std;
int pa[10000],d[10000],b[10000],t[10000],kq[10000],mi=-999999;
int s,n,m,ma,vt;
typedef pair <int,int> ii;
vector <ii> a[10000];
void dijkstra (int s)
{
    priority_queue <ii, vector<ii>, greater<ii>> pq;
    for (int i=1; i<=n; i++)
    {
        d[i]=999999;
        b[i]=0;
    }
    d[s]=0;
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
    freopen("BANHANG.INP","r",stdin);
    freopen("BANHANG.OUT","w",stdout);
    cin>>n>>m>>s;
    for (int i=1; i<=m; i++)
    {
        int t1,t2,we;
        cin>>t1>>t2>>we;
        a[t1].push_back(ii(t2,we));
    }
    dijkstra(s);
    for (int i=1; i<=n; i++)
        t[i]=d[i];
    for (int i=1; i<=n; i++)
    {
        if (i!=s)
        {
            dijkstra(i);
            t[i]=t[i]+d[s];
        }
    }
    for (int i=1; i<=n; i++)
        if (t[i]>ma) ma=t[i];
    kq[s]=ma;
    for (int i=1; i<=n; i++)
        t[i]=0;
    for (int i=1; i<=n; i++)
    {
        if (i!=s)
        {
            dijkstra(i);
            for (int j=1; j<=n; j++)
                t[j]=d[j];
            for (int j=1; j<=n; j++)
            {
                if (j!=i)
                {
                    dijkstra(j);
                    t[j]=t[j]+d[i];
                }
            }
            ma=0;
            for (int j=1; j<=n; j++)
                if (t[j]>ma) ma=t[j];
            kq[i]=ma;
        }
    }
    vt=1;
    mi=kq[1];
    for (int i=2; i<=n; i++)
        if (kq[i]<mi)
        {
            mi=kq[i];
            vt=i;
        }
    cout<<kq[s]<<"\n"<<vt;
    return 0;
}
