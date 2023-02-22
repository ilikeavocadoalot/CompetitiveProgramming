#include <bits/stdc++.h>
using namespace std;
long long int t,n,m,a,b,f[15010];
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("10689.INP","r",stdin);
    freopen("10689.OUT","w",stdout);
    f[0]=0;
    f[1]=1;
    for (int i=2; i<=15005; i++)
        f[i]=(f[i-1]%10000+f[i-2]%10000)%10000;
    cin>>t;
    for (int index = 1; index<=t; index++)
    {
        cin>>a>>b>>n>>m;
        int mu=1;
        for (int i=1; i<=m; i++)
            mu=mu*10;
        int ans;
        if (n%15000==0) ans = a%mu;
        else ans = (((f[n%15000]*b)%mu + (f[(n-1)%15000]*a)%mu))%mu;
        cout<<ans<<"\n";
    }
    return 0;
}
