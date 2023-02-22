#include <bits/stdc++.h>
using namespace std;
bool pr[1000010];
long long int n;
void sang (long long int n)
{
    for (long long int i=2; i<=n; i++)
    {
        if (pr[i]==true)
        {
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
    freopen("543.INP","r",stdin);
    freopen("543.OUT","w",stdout);
    memset(pr,true,1000010);
    sang(1000010);
    n=1;
    while (true)
    {
        cin>>n;
        if (n==0) break;
        int i=2;
        while (i<=n/2)
        {
            if (pr[i]==true && pr[n-i]==true)
            {
                cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
                i=n;
            }
            i++;
        }
    }
    return 0;
}
