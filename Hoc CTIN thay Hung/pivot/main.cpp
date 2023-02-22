#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a[1000000],mn[1000000],mx[1000000];
    bool kt[100000];
    int n,i,t1=-99999999,t2=99999999,dem=0;
    cin>>n;
    for (i=1; i<=n; i++)
        cin>>a[i];
    for (i=n; i>0; i--)
    {
        if (a[i]<t2) t2=a[i];
        mn[i]=t2;
    }
    for (i=1; i<=n; i++)
    {
        if (a[i]>t1) t1=a[i];
        mx[i]=t1;
    }
    mx[0]=0;
    mn[n+1]=9999999;
    for (i=1; i<=n; i++)
    {
        if ((mx[i-1]<a[i]) && (mn[i+1]>a[i]))
        {
            dem++;
        }
    }
    cout<<dem;
    return 0;
}
