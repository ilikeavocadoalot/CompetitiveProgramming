#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],n,m,k,r,l[1001][1001],u[1001][1001];
int main()
{
    freopen("BANGCN.INP","r",stdin);
    freopen("BANGCN.OUT","w",stdout);
    cin>>k>>r>>n>>m;
    a[1][1]=l[1][1]=u[1][1]=k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (i!=1 || j!=1)
            {
                a[i][j]=(l[i][j-1]+u[i-1][j])%r;
                l[i][j]=(l[i][j-1]+a[i][j]);
                u[i][j]=(l[i][j]+u[i-1][j]);
            }
    cout<<a[n][m];
    return 0;
}
