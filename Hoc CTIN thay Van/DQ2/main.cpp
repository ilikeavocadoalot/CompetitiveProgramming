#include <bits/stdc++.h>
using namespace std;
long long int S(int n)
{
    if (n==0) return 0;
    if (n%2==0) return -n+S(n-1);
    else return n+S(n-1);
}
int main()
{
    freopen ("DQ2.INP","r",stdin);
    freopen ("DQ2.OUT","w",stdout);
    long long int n;
    cin>>n;
    cout<<S(n);
    return 0;
}
