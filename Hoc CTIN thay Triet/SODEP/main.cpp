#include <bits/stdc++.h>
using namespace std;
int n,t,a[100005], pf[100005];
int main()
{
    freopen("SODEP.INP","r",stdin);
    freopen("SODEP.OUT","w",stdout);
    for (int i=2; i<=100001; i++)
        if (i%10==2 || i%10==5 || i%10==7 || i%10==9) a[i]=1;
    for (int i=2; i<=100001; i++)
        pf[i]=a[i]+pf[i-1];
    cin>>t;
    for (int index=1; index<=t; index++)
    {
        int l,r;
        cin>>l>>r;
        cout<<pf[r]-pf[l]<<"\n";
    }
    return 0;
}
