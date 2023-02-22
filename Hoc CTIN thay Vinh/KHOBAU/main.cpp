#include <bits/stdc++.h>
using namespace std;
int n,m,k,d[10000],pa[10000],x1,p1,x2,p2,x3,p3,kq,kq1;
bool mark[10000];
typedef pair <int,int> ii;
vector <ii> a[10000];
void dijkstra(int s,int f)
{
    for(int i=1; i<=n; i++)
    {
        d[i]=999999;
        mark[i]=false;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[s]=0;
    pq.push(ii(0,s));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if (mark[u]) continue;
		if (u==f) break;
		mark[u]=true;
        for (int i=0; i<(int)a[u].size(); i++)
        {
            int v=a[u][i].first;
			int w=a[u][i].second;
            if (d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push(ii(d[v],v));
            }
        }

    }
}
int main()
{
    freopen("KHOBAU.INP","r",stdin);
    freopen("KHOBAU.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        int t1,t2,we;
        cin>>t1>>t2>>we;
        a[t1].push_back(ii(t2,we));
        a[t2].push_back(ii(t1,we));
    }
    if (k==1)
    {
        cin>>x1>>p1;
        dijkstra(1,x1);
        kq=kq+d[x1];
        dijkstra(x1,n);
        kq=kq+d[n];
        cout<<kq+p1;
    }
    else if (k==2)
    {
        cin>>x1>>p1;
        cin>>x2>>p2;
        dijkstra(1,x1);
        kq=kq+d[x1];
        dijkstra(x1,x2);
        kq+=d[x2];
        dijkstra(x2,n);
        kq+=d[n];
        dijkstra(1,x2);
        kq1=kq+d[x2];
        dijkstra(x2,x1);
        kq1+=d[x1];
        dijkstra(x1,n);
        kq1+=d[n];
        if (kq1<kq) kq=kq1;
        cout<<(kq+p1+p2);
    }
    else
    {
        cin>>x1>>p1;
        cin>>x2>>p2;
        cin>>x3>>p3;
        dijkstra(1,x1);
        kq+=d[x1];
        dijkstra(x1,x2);
        kq+=d[x2];
        dijkstra(x2,x3);
        kq+=d[x3];
        dijkstra(x3,n);
        kq+=d[n];
        dijkstra(1,x1);
        kq1+=d[x1];
        dijkstra(x1,x3);
        kq1+=d[x3];
        dijkstra(x3,x2);
        kq1+=d[x2];
        dijkstra(x2,n);
        kq1+=d[n];
        if (kq1<kq) kq=kq1;
        dijkstra(1,x2);
        kq1+=d[x2];
        dijkstra(x2,x1);
        kq1+=d[x1];
        dijkstra(x1,x3);
        kq1+=d[x3];
        dijkstra(x3,n);
        kq1+=d[n];
        if (kq1<kq) kq=kq1;
        dijkstra(1,x2);
        kq1+=d[x2];
        dijkstra(x2,x3);
        kq1+=d[x3];
        dijkstra(x3,x1);
        kq1+=d[x1];
        dijkstra(x1,n);
        kq1+=d[n];
        if (kq1<kq) kq=kq1;
        dijkstra(1,x3);
        kq1+=d[x3];
        dijkstra(x3,x1);
        kq1+=d[x1];
        dijkstra(x1,x2);
        kq1+=d[x2];
        dijkstra(x2,n);
        kq1+=d[n];
        if (kq1<kq) kq=kq1;
        dijkstra(1,x3);
        kq1+=d[x3];
        dijkstra(x3,x2);
        kq1+=d[x2];
        dijkstra(x2,x1);
        kq1+=d[x1];
        dijkstra(x1,n);
        kq1+=d[n];
        if (kq1<kq) kq=kq1;
        cout<<(kq+p1+p2+p3);
    }
    return 0;
}
