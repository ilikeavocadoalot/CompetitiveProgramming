#include <bits/stdc++.h>
using namespace std;
long long int a[1000005];
int main()
{
    long long int n,m,s=0;
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    for (int i=0; i<n-1; i++)
    {
        if (m-a[i]<=0) continue;
        int t=upper_bound(a+i+1,a+n,m-a[i])-a;
        s= s+ max((t-i-1),0);
    }
    cout<<s;
    return 0;
}
