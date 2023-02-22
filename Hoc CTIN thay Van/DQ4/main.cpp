#include <bits/stdc++.h>
using namespace std;
long long int n,m,i;
int UCLN (int n,int m)
{
    i--;
    if (i==1) return 1;
    if ((n%i==0) && (m%i==0)) return i;
    else UCLN(n,m);
}
int main()
{
    freopen ("DQ4.INP","r",stdin);
    freopen ("DQ4.OUT","w",stdout);
    cin>>n>>m;
    i=min(n,m)+1;
    cout<<UCLN(n,m);
    return 0;
}
