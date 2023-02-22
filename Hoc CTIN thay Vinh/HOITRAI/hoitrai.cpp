#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
int n,m,q,d[310][310],dem[310][310];
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("HOITRAI.INP","r",stdin);
    freopen("HOITRAI.OUT","w",stdout);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if (i==j) d[i][j]=0;
            else d[i][j]=inf;
            dem[i][j]=0;
        }
    for(int i=1;i<=n;i++)
        dem[i][i]=1;
    for (int i=1; i<=m; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        d[t1][t2]=1;
        d[t2][t1]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if (d[i][k]+d[k][j]<d[i][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
    for (int index=1; index<=q; index++)
    {
        int t1,t2;
        cin>>t1>>t2;
        cout<<d[t1][t2]<<"\n";
    }
    return 0;
}
