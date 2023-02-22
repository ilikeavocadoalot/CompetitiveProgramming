#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int a[500], b[500], c[500];
int n,kq;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("DEMTG.INP","r",stdin);
    freopen("DEMTG.OUT","w",stdout);
    cin>>n;
    int k,k1;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) cin>>b[i];
    for (int i=0; i<n; i++) cin>>c[i];
    sort(a,a+n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            k=0;
            while (k<n && a[k]<=abs(b[i]-c[j])+1)
                k+=1;
            if (k<n)
            {
                k1=n-1;
                while (0<=k1 && a[k1]>(b[i]+c[j])-1)
                    k1-=1;
                kq+=k1-k+1;
            }
        }
    }
    cout<<kq;
    return 0;
}
