#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DOMDOM.INP","r",stdin);
    freopen("DOMDOM.OUT","w",stdout);
    int n,h,dem=0,m,a[100000],b[100000],t1=-1,t2=-1;
    cin>>n>>h;
    for (int i=1; i<=n; i++)
    {
        if (i%2==0)
        {
            t1++;
            cin>>a[t1];
        }
        else
        {
            t2++;
            cin>>b[t2];
        }
    }
    m=9999999;
    sort(a,a+(n/2));
    sort(b,b+(n/2));
    for (int i=1; i<=h; i++)
    {
        int tmp1 = (n/2)- (lower_bound(a,a+(n/2),i)-a);
        int tmp2 = (n/2)- (lower_bound(b,b+(n/2),h-i+1)-b);
        if (m==tmp1+tmp2) dem++;
        if (m>tmp1+tmp2)
        {
            m=tmp1+tmp2;
            dem=1;
        }
    }
    cout<<m<<" "<<dem;
    return 0;
}






