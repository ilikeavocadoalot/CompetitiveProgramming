#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("SOXAU.INP","r",stdin);
    freopen("SOXAU.OUT","w",stdout);
    int t,n;
    int i,j,k;
    long long int h[10000];
    for (i=0; i<=30; i++)
        for (j=0; j<=38; j++)
            for (k=0; k<=26; k++)
                if ((pow(2,i) * pow(3,j) * pow(5,k)) <=pow(10,10))
                {
                    t++;
                    h[t]=pow(2,i) * pow(3,j) * pow(5,k);
                }
    sort(h,h+t);
    while (cin>>n)
    {
        if (n==0)exit;
        cout<<h[n]<<endl;
    }
    return 0;
}
