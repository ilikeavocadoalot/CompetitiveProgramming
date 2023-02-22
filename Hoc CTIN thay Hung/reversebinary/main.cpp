#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long n,kq,t;
    string s,a;
    cin>>n;
    while (n!=0)
    {
        if (n%2==0) s='0'+s;
        else s='1'+s;
        n=n/2;
    }
    t=1;
    for (int i=s.size()-1;i>=0;i--)
        a=a+s[i];
    for (int i=a.size()-1;i>=0;i--)
    {
        if (a[i]!='0') kq=kq+t;
        t=t*2;
    }
    cout<<kq;
    return 0;
}
