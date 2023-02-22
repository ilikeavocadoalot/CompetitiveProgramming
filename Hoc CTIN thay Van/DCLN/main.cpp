#include <bits/stdc++.h>
using namespace std;
long long int a[100000],n,s1,s2=-1e18;
int main()
{
    freopen("DCLN.INP","r",stdin);
    freopen("DCLN.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s1+=a[i];
        s2=max(s1,s2);
        if (s1<0) s1=0;
    }
    cout<<s2;
    return 0;
}
