#include <bits/stdc++.h>
using namespace std;
int a[10000],x[10000],b[10000],m,n,s,k;
void tunglamroi(int i)
{
    for (int j=1; j<=n; j++)
    {
        if (m+a[j]<=s && i<=k &&b[a[j]]==0)
        {
            x[i]=a[j];
            m+=a[j];
            b[a[j]]=1;
            if (m==s)
            {
                if (i==k)
                {
                    cout<<"YES"<<"\n";
                    for (int t=1; t<=k; t++)
                        cout<<x[t]<<" ";
                    exit(0);
                }
            }
            else tunglamroi(i+1);
            b[a[j]]=0;
            m-=a[j];
        }
    }
}
int main()
{
    freopen("MONEY.INP","r",stdin);
    freopen("MONEY.OUT","w",stdout);
    cin>>n>>k>>s;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a,a+n);
    tunglamroi(1);
    cout<<"NO"<<"\n";
    return 0;
}
