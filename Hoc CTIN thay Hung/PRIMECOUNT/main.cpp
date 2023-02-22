#include <bits/stdc++.h>
using namespace std;
bool pr[1000010];
bool ktra (long long int n)
{
    if (n<=1) return false;
    for (long long int i=2; i<=trunc(sqrt(n)); i++)
        if (n%i==0) return false;
    return true;
}
void sang (long long int l, long long int r)
{
    memset(pr,true,sizeof(pr));
    long long int a = l;
    long long int b = r;
    for (long long int i=a; i<=a*a; i++)
        if (ktra(i)==false) pr[i-a+1]=false;
    for (long long int i=a; i<=b; i++)
    {
        if (pr[i-a+1]==true)
        {
            long long int j=i*i;
            while (j<=b)
            {
                pr[j-a+1]=false;
                j=j+i;
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
    int l,r;
    int t;
    cin>>t;
    for (int index=1; index<=t; index++)
    {
        int dem=0;
        cin>>l>>r;
        sang(l,r);
        for (int i=l; i<=r; i++)
            if (pr[i-l+1]==true) dem++;
        cout<<dem<<"\n";
    }
    return 0;
}
