#include <bits/stdc++.h>
using namespace std;
int d[1000],danhdau[1000],n,m,p,q,t,si,sj,si1,sj1,si2,sj2,si3,sj3,c[100][100];
char a[100][100];
int timmin()
{
    int tr=999999, u=0;
    for (int i=1; i<=n; i++)
        if (!danhdau[i] && try>d[i])
        {
            tr=d[i];
            u=i;
        }
    return u;
}
void dijkstra (int )
{
    d[t1]=0;
    while (true)
    {
        int u=getmin();
        if (u==0||u==f) break;
        danhdau[u]==1;
        for (int v=1; v<=n; v++)
            if (!danhdau[v] && d[v]>d[u]+c[u][v])
            {
                d[v]=d[u]+c[u][v];

            }
    }
}
int main()
{
    cin>>n>>m>>p>>q>>t;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if (i==j) c[i][j]=0;
            else c[i][j]=999999;
            if (a[i][j]=='X')
            {
                si=i;
                sj=j;
            }
            if (a[i][j]=='K' && si1==0 && sj1==0)
            {
                si1=i;
                sj1=j;
            }
            else if (a[i][j]=='K' && si2==0 && sj2==0)
            {
                si2=i;
                sj2=j;
            }
            else if (a[i][j]=='K' && si3==0 && sj3==0)
            {
                si3=i;
                sj3=j;
            }
        }
    return 0;
}
