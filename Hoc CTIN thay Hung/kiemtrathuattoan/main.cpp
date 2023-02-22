#include <bits/stdc++.h>
using namespace std;
bool pr[1000010];
int dem [1000010];
void sang (long long int n)
{
    memset(pr,true,sizeof(pr));
    for (long long int i=2; i<=n; i++)
    {
        if (pr[i]==true)
        {
            dem[i]=1;
            long long int j=i*i;
            while (j<=n)
            {
                pr[j]=false;
                j=j+i;
            }
        }
    }
}
int main()
{
    int l,r;
    int t;
    cin>>t;
    sang(1000010);
    dem[1]=0;
    for (int i=2; i<=1000000; i++)
        dem[i]=dem[i]+dem[i-1];
    for (int index=1; index<=t; index++)
    {
        cin>>l>>r;
        cout<<dem[r]-dem[l]<<"\n";
    }
    return 0;
}
