#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,a[100000],dem=0;
    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    for (int i=0; i<n; i++)
        if (binary_search(a,a+n,a[i]+k)) dem++;
    cout<<dem<<endl;
    return 0;
}
