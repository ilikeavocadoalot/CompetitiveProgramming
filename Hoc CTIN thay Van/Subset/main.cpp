#include <iostream>
using namespace std;
const int mod = 1e9-7;
int n,x,a[10000],t[10000],w[10000][10000];
int main()
{
    freopen("SubsetSum.inp","r",stdin);
    freopen("SubsetSum.out","w",stdout);
    cin>>n>>x;
    t[0]=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        t[i]=t[i-1]+a[i];
    }
    if (x>t[n])
    {
        cout<<0;
        return 0;
    }
    for (int i=0; i<=n; i++)
        w[i][0]=1;
    for (int j=1; j<=x; j++)
        w[0][j]=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=t[i]; j++)
            if (j>=a[i])
                w[i][j]=(w[i-1][j]+w[i-1][j-a[i]])%mod;
            else w[i][j]=w[i-1][j];
    cout<<w[n][x]%mod;
    return 0;
}
