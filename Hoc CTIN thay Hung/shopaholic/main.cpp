#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
    int n,a[200000];
    long tong;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n, greater<int>());
    for (int i=0; i<n; i+=3)
    {
        if ((i+1)>=n || (i+2)>=n)
            break;
        tong+=a[i+2];
    }
    cout<<tong;
    return 0;
}
