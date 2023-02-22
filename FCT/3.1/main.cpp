#include <bits/stdc++.h>
using namespace std;
long long int n,dem=0;
int main()
{
    cin>>n;
    while (n>=10 && n!=0)
    {
        dem++;
        n-=10;
    }
    while (n>=5 && n!=0)
    {
        dem++;
        n-=5;
    }
    while (n>=1 && n!=0)
    {
        dem++;
        n-=1;
    }
    cout<<dem;
    return 0;
}
