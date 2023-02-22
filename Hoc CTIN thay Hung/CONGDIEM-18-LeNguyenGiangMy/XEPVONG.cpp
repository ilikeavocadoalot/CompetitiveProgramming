#include <bits/stdc++.h>
#include<iomanip>
using namespace std;
long long int n;
double ma=999999,d,c[100],a[100];
double dis (double a, double b)
{
    return (sqrt((a+b)*(a+b)-(a-b)*(a-b)));
}
int main()
{
    freopen("XEPVONG.INP","r",stdin);
    freopen("XEPVONG.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    do
    {
        memset(c,0,sizeof(c));
        d=0;
        c[1]=a[1];
        for (int i=2;i<=n;i++)
        {
            for (int j=1;j<i;j++)
                c[i]=max(a[i],c[j]+dis(a[i],a[j]));
        }
        for (int i=1;i<=n;i++)
            d = max(c[i]+a[i],d);
        ma =min(ma,d);
    } while (std::next_permutation(a+1,a+n+1));
    cout<<fixed<<setprecision(3)<<ma;
    return 0;
}
