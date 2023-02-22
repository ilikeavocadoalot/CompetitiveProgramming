#include <bits/stdc++.h>
using namespace std;
int d[1000][1000],g[1000][1000],p[1000][1000],a,b,c,n,m;
int main()
{
    freopen("TIEPTE.INP","r",stdin);
    freopen("TIEPTE.OUT","w",stdout);
    cin>>n>>m;
    cin>>a>>b>>c;

    for (int i=0; i<m; i++)
    {
        int x,y,dd,pp;
        cin>>x>>y>>dd>>pp;
        g[x][y]=1;
        d[x][y]=dd;
        p[x][y]=pp;
    }
    for(int k=1;k<=n;k++)
        for(int u=1;u<=n;u++)
            for(int v=1;v<=n;v++)
            {
                if (d[u][v]==0) d[u][v]=99999999;
                if (d[u][k]==0) d[u][k]=99999999;
                if (d[k][v]==0) d[k][v]=99999999;
                d[u][v]=min(d[u][v],d[u][k]+d[k][v]);
                if (p[u][v]==0) p[u][v]=99999999;
                if (p[u][k]==0) p[u][k]=99999999;
                if (p[k][v]==0) p[k][v]=99999999;
                p[u][v]=min(p[u][v],max(p[u][k],p[k][v]));
            }
    cout<<d[a][b]+d[b][c]<<"\n";
    cout<<max (p[a][b],p[b][c]);
    return 0;
}
