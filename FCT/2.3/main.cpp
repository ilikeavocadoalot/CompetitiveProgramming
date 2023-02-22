#include <bits/stdc++.h>
using namespace std;
long long int a,b,tam;
int main()
{
    cin>>a>>b;
    while (b!=0)
    {
        tam=a;
        a=b;
        b=tam%a;
    }
    cout<<a;
    return 0;
}
