#include <bits/stdc++.h>
using namespace std;
int n,c,a[10000],f[10000][10000],v[10000];
int main()
{
    freopen("CHEPNHAC.INP","r",stdin);
    freopen("CHEPNHAC.OUT","w",stdout);
    cin>>n>>c;
    for (int i=1; i<=c; i++)
        cin>>a[i];
    for (int i=1; i<=c; i++)
        for (int j=0;j<=n;j++)
        {
            f[i][j]=f[i-1][j];
            if ((a[i]<=j)&&(a[i]+f[i-1][j-a[i]]>f[i][j]))
                f[i][j]= a[i]+f[i-1][j-a[i]];
        }
    cout <<f[c][n]<<endl;
    return 0;
}
