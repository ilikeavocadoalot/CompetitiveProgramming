#include <bits/stdc++.h>
using namespace std;
int n,w,m[10000],v[10000],f[10000][10000];
int main()
{
    freopen("BALO.INP","r",stdin);
    freopen("BALO.OUT","w",stdout);
    cin>>n>>w;
    for (int i=1; i<=n; i++)
        cin>>m[i]>>v[i];
    for (int i=1; i<=n; i++)
        for (int j=0;j<=w;j++)
        {
            f[i][j]=f[i-1][j];
            if ((m[i]<=j)&&(v[i]+f[i-1][j-m[i]]>f[i][j]))
                f[i][j]= v[i]+f[i-1][j-m[i]];
        }
    cout << f[n][w]<<endl;
    for( int i=n ; n>0 ;n--)
    {
        if (f[n][w]!=f[n-1][w])
        {
            cout<<n<<" ";
            w=w-m[n];
        }
    }
    return 0;
}
