#include <bits/stdc++.h>
using namespace std;
int n,a[50005],l[50005],kq;
int main()
{
    freopen("STOCKS2.INP","r",stdin);
    freopen("STOCKS2.OUT","w",stdout);
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    l[0]=1;
    for (int i=1; i<n; i++)
    {
        l[i]=1;
        for (int j=0; j<i; j++)
            if (a[i]>a[j] && l[i]<l[j]+1)
                l[i]=l[j]+1;
    }
    kq=0;
    for (int i=1; i<=n; i++)
        kq = max(kq,l[i]);
    cout<<kq;
    return 0;
}
