#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,dem=1,a[100000];
    cin>>n>>k;
    if (n<k) cout<<0<<endl;
    else if (n==k) cout<<"oo"<<endl;
    else
    {
        long long int t=n-k;
        int i=2;
        while (t!=1)
        {
            if (t%i==0)
            {
                t/=i;
                a[i]++;
            }
            else i++;
        }
        for (int i=k+1; i<=sqrt(n-k); i++)
            if (a[i]!=0) dem=dem*(a[i]+1);
        cout<<dem<<endl;
    }
    return 0;
}
