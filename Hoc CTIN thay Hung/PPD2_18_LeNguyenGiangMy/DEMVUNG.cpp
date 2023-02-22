#include <bits/stdc++.h>
using namespace std;
int t;
long long int gt (int n)
{
    long long int res=1;
    for (int i=1; i<=n; i++)
        res*=i;
    return res;
}
int main()
{
    freopen("DEMVUNG.INP","r",stdin);
    freopen("DEMVUNG.OUT","w",stdout);
    cin>>t;
    for (int index=1; index<=t; index++)
    {
        int n;
        cin>>n;
        cout<<1+(gt(n)/(gt(2)*gt(n-2)))+(gt(n)/(gt(4)*gt(n-4)))<<"\n";
    }
    return 0;
}
