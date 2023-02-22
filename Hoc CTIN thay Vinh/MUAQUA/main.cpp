#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
vector <ii> a[1000];
int n,m,y,x,z,s,q,kq;
int d[1000],dd[1000],ddd[1000];
bool mark[1000];
ii xx[1000],yy[1000],zz[1000];
void dijkstra(int s)
{
    for(int i=1; i<=n; i++)
    {
        d[i]=9999999;
        mark[i]=false;
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
        for (int i=0; i<(int)a[u].size(); i++)
        {
            int v=a[u][i].first;
			int w=a[u][i].second;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push(ii(d[v],v));
            }
        }
    }
}
int ktra (int x)
{
    int vt;
    kq=999999;
    for (int i=0; i<x; i++)
    {
        if (kq>)
    }
}
int main()
{
    freopen("MUAQUA.INP","r",stdin);
    freopen("MUAQUA.OUT","w",stdout);
    cin>>n>>m>>x>>y>>z>>s>>q;
    for (int i=1; i<=m; i++)
    {
        int t1,t2,we;
        cin>>t1>>t2>>we;
        a[t1].push_back(ii(t2,we));
        a[t2].push_back(ii(t1,we));
    }
    for (int i=1; i<=x; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        xx[i].first=t1;
        xx[i].second=t2;
    }
    for (int i=1; i<=y; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        yy[i].first=t1;
        yy[i].second=t2;
    }
    for (int i=1; i<=z; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        zz[i].first=t1;
        zz[i].second=t2;
    }
    dijkstra(s);
    int tam1,tam2,tam3;
    tam1=tam2=tam3=999999;
    for (int i=1; i<=x; i++)
        tam1 = min (d[xx[i].first]+xx[i].second,tam1);
    for (int i=1; i<=y; i++)
        tam2 = min (d[yy[i].first]+yy[i].second,tam2);
    for (int i=1; i<=z; i++)
        tam3 = min (d[zz[i].first]+zz[i].second,tam3);
    if (q==1) cout<<tam1;
    else if (q==2) cout<<tam2;
    else if (q==3) cout<<tam3;
    else if (q==4) cout<<tam1+tam2;
    else if (q==5) cout<<tam1+tam3;
    else if (q==6) cout<<tam2+tam3;
    else cout<<tam1+tam2+tam3;
    return 0;
}
