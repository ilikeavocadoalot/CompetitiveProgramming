#include <bits/stdc++.h>
using namespace std;
int a[100000],b[100000],n,m,i,dem;
bool comp(const int a, const int b)
{
   return a > b;
}
int main()
{
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=m; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    sort(a,a+m,comp);
    sort(b,b+n,comp);
    dem=0;
    int j=1;
    for (int i=1; i<=n; i++)
    {
        j=upper_bound(a,a+n,a[i])-a;
        if (j>0 && j<=n) dem++;
    }
    cout<<dem;
    return 0;
}
