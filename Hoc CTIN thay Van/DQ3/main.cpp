#include <bits/stdc++.h>
using namespace std;
long long int n, a[10000];
void Daonguoc(long long int so, int &n)
{
    int t=n;
    if (so==0)
    {
        for (int i=0; i<t; i++)
            cout<<a[i];
        return;
    }
    a[n]=so%10;
    t=n+1;
    so/=10;
    Daonguoc(so,t);
}
int main()
{
    freopen ("DQ3.INP","r",stdin);
    freopen ("DQ3.OUT","w",stdout);
    cin>>n;
    int t=n-n;
    Daonguoc(n,t);
    return 0;
}
