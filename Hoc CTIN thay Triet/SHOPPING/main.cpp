#include <bits/stdc++.h>
using namespace std;
long long int n,a[200005],d,c[200005],dem,tam;
int main()
{
    freopen("SHOPPING.INP","r",stdin);
    freopen("SHOPPING.OUT","w",stdout);
    cin>>n>>d;
    cin>>a[1];
    for (int i=2; i<=n; i++)
    {
        cin>>a[i];
        c[i+1]=c[i-2]+a[i]*a[i-1];
        if (a[i]+c[i]<=d && i % 2 !=0) dem+=i/2+1;
        else if (a[i]+c[i]<=d) dem+=i/2;
        else dem++;
        if (a[i+1]<=d) dem+=i/2;
        else dem++;
    }
    cout<<dem+1;
    return 0;
}
