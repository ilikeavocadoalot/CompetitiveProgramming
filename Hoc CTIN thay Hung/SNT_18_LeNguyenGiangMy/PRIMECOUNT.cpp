#include <bits/stdc++.h>
using namespace std;
int l,r;
bool pr[1000010];
int a[1000010];
long long int n;
void sang (long long int n)
{
    for (long long int i=2; i<=n; i++)
    {
        if (pr[i]==true)
        {
            a[i]=1;
            long long int j=i*i;
            while (j<=n)
            {
                pr[j]=false;
                j+=i;
            }
        }
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("PRIMECOUNT.INP","r",stdin);
    freopen("PRIMECOUNT.OUT","w",stdout);
    memset(pr,true,1000010);
    sang(1000010);
    for (int i=2; i<=1000010; i++)
        a[i]=a[i]+a[i-1];
    int t;
    cin>>t;
    for (int index=1; index<=t; index++)
    {
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l]<<"\n";
    }
    return 0;
}
