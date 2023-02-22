#include <bits/stdc++.h>
using namespace std;
int a[10000],n,b[10000],c[10000],d[10000];
int main()
{
    freopen("MUAVE.INP","r",stdin);
    freopen("MUAVE.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i]>>c[i];
    d[0]=0;
    d[1]=a[1];
    d[2]=min(a[1]+a[2],b[1]);
    for (int i=3; i<=n; i++)
        d[i]=min(d[i-1]+a[i],min (d[i-2]+b[i-1], d[i-3]+c[i-2]));
    cout<<d[n];
    return 0;
}
