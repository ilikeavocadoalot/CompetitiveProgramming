#include <bits/stdc++.h>
using namespace std;
int a[10000][10000],d[10000];
int capa[10000],capb[10000],capc[10000];
int n,m,y,p,q,k,vta,vtb,vtc,mi1,mi2,mi3;
bool mark[10000];
#define inf 1e9
int getmin()
{
    int minD=inf, u=0;
    for(int i=1;i<=n;i++)
        if (!mark[i] && minD>d[i])
        {
            minD=d[i];
            u=i;
        }
    return u;
}
void dijkstra(int s)
{
    for(int i=1; i<=n; i++)
    {
        d[i]=inf; mark[i]=false;
    }
    d[s]=0;
    while(true)
    {
        int u=getmin();
        if (u==0) break;
        mark[u]=true;
        for(int v=1; v<=n; v++)
            if(!mark[v] && d[v]>d[u]+a[u][v])
                d[v]=d[u]+a[u][v];
    }
}
int main()
{
    freopen("DVGH.INP","r",stdin);
    freopen("DVGH.OUT","w",stdout);
    cin>>n>>m>>y>>p>>q>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (i==j) a[i][j]=0;
            else a[i][j]=inf;
	for(int i=1;i<=m;i++)
    {
        int t1,t2,w;
        cin>>t1>>t2>>w;
        a[t1][t2]=w;
        a[t2][t1]=w;
	}
	for (int i=1; i<=p; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        capa[t1]=t2;
    }
    for (int i=1; i<=q; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        capb[t1]=t2;
    }
    for (int i=1; i<=k; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        capc[t1]=t2;
    }
    dijkstra(y);
    int mi1=999999;
    for (int i=1; i<=n; i++)
        if (capa[i]!=0)
            if (d[i]+capa[i]<mi1)
            {
                mi1=d[i]+capa[i];
                vta=i;
            }
    cout<<mi1<<endl;
    mi2=999999;
    for (int i=1; i<=n; i++)
        if (capb[i]!=0)
            if (d[i]+capb[i]<mi2)
            {
                mi2=d[i]+capb[i];
                vtb=i;
            }
    mi3=999999;
    for (int i=1; i<=n; i++)
        if (capc[i]!=0)
            if (d[i]+capc[i]<mi3)
            {
                mi3=d[i]+capc[i];
                vtc=i;
            }
    int t=mi1+mi2+mi3;
    int kq=t;
    t=999999;
    for (int i=1; i<=n; i++)
        if (capa[i]!=0 && capb[i]!=0)
            if (d[i]+capa[i]+capb[i]<t)
                t=d[i]+capa[i]+capb[i];
    kq=min(kq,t+d[vtc]+capc[vtc]);
    t=999999;
    for (int i=1; i<=n; i++)
        if (capb[i]!=0 && capc[i]!=0)
            if (d[i]+capc[i]+capb[i]<t)
                t=d[i]+capc[i]+capb[i];
    kq=min(kq,t+d[vta]+capa[vta]);
    t=999999;
    for (int i=1; i<=n; i++)
        if (capa[i]!=0 && capc[i]!=0)
            if (d[i]+capc[i]+capa[i]<t)
                t=d[i]+capc[i]+capa[i];
    kq=min(kq,t+d[vtb]+capb[vtb]);
    t=999999;
    for (int i=1; i<=n; i++)
        if (capa[i]!=0 && capc[i]!=0 && capb[i]!=0)
            if (d[i]+capc[i]+capa[i]+capb[i]<t)
                t=d[i]+capc[i]+capa[i]+capb[i];
    kq=min(kq,t);
    cout<<kq;
    return 0;
}
