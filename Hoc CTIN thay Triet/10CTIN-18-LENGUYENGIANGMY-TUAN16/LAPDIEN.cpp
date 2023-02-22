#include <bits/stdc++.h>
using namespace std;
int n,m,a,mi,b;
float d[1000],c[1000][1000];
bool mark[1000];
float k;
typedef pair <int,int> ii;
ii toado[1000];
int getmin()
{
    float minD=999999.0;
    int u=0;
    for(int i=1;i<=n;i++)
        if (!mark[i]&&minD>d[i])
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
        d[i]=999999.0;
        mark[i]=false;
    }
    d[s]=0.0;
    while (true)
    {
        int u=getmin();
        if (u==0) break;
        mark[u]=true;
        for (int v=1; v<=n; v++)
            if (!mark[v] && d[v]>d[u]+c[u][v])
                d[v]=d[u]+c[u][v];
    }
}
int main()
{
    freopen("LAPDIEN.INP","r",stdin);
    freopen("LAPDIEN.OUT","w",stdout);
    cin>>n>>m;
    cin>>k;
    for (int i=1; i<=n; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        toado[i].first=t1;
        toado[i].second=t2;
    }
    for (int i=1; i<=n; i++)
    {
        int x1,y1;
        x1=toado[i].first;
        y1=toado[i].second;
        for (int j=1; j<=n; j++)
            if (i!=j)
            {
                int x2,y2;
                x2=toado[j].first;
                y2=toado[j].second;
                if (hypot(x1-x2,y1-y2)<=k)
                {
                    c[i][j]=hypot(x1-x2,y1-y2);
                    c[j][i]=hypot(x1-x2,y1-y2);
                }
                else
                {
                    c[i][j]=999999.0;
                    c[j][i]=999999.0;
                }
            }
            else
            {
                c[i][j]=0.0;
                c[j][i]=0.0;
            }
    }
    for (int i=1; i<=m; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        c[t1][t2]=0;
        c[t2][t1]=0;
    }
    dijkstra(1);
    cout<<int(d[n]*1000);
    return 0;
}
