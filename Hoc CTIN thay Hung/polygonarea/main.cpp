#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100000], b[100000], n, tong=0;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    tong = abs(a[n]*b[1] - b[n]*a[1]);
    for (int i=2; i<=n; i++)
        tong+= abs((a[i-1]*b[i])-(b[i-1]*a[i]));
    if (tong%2==0) cout<<tong/2;
    else cout<<tong/2<<".5";
    return 0;
}
