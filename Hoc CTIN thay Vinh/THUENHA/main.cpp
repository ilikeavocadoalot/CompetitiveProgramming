#include <bits/stdc++.h>
using namespace std;
int n,m,p,dd[10000],d[10000],kq,b[10000],mi,nn,start,en;
bool mark[10000];
typedef pair <int,int> ii;
vector <ii> a[10000];
int dijkstra(int s,int f)
{
    for(int i=1; i<=n; i++)
    {
        d[i]=999999;
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
    return d[f];
}
int kc ()
{
    int mi=INT_MAX;
    do
    {
        int t=dijkstra(dd[0],dd[1]);
        for (int i=1; i<p-1; i++)
            t+=dijkstra(dd[i],dd[i+1]);
        if (t<mi)
        {
            mi=t;
            start=dd[0];
            en=dd[p-1];
        }
    } while (next_permutation(dd,dd+p));
    return mi;
}
int main()
{
    //freopen("THUENHA.INP","r",stdin);
    //freopen("THUENHA.OUT","w",stdout);
    cin>>n>>m>>p;
    memset(b,0,sizeof(b));
    memset(a,{},sizeof(a));
    for (int i=0; i<p; i++)
    {
        cin>>dd[i];
        b[dd[i]]=1;
    }
    for (int i=0; i<m; i++)
    {
        int t1,t2,we;
        cin>>t1>>t2>>we;
        a[t1].push_back(ii(t2,we));
        a[t2].push_back(ii(t1,we));
    }
    kq=INT_MAX;
    int way = kc();
    for (int i=1; i<=n; i++)
    {
        if (b[i]==0)
            if (a[i].size()>0)
                kq=min(kq,dijkstra(i,start) + dijkstra(i,en)+way);
    }
    cout<<kq;
    return 0;
}
