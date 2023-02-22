#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
    int a[]={1,5,8,9,6,7,3,4,2,0};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n,greater<int>());
    for (int i=0; i<n; i++)
        cout<<a[i]<<' ';
    return 0;
}
