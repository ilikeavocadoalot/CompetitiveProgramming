#include <bits/stdc++.h>
using namespace std;
long long int a,b,tam,t;
int main()
{
    cin>>a>>b;
    t=a*b;
    while (b!=0)
    {
        tam=a;
        a=b;
        b=tam%a;
    }
    cout<<t/a;
    return 0;
}
