#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n,t=0;
    bool a[42];
    for (int i=0;i<=42;i++)
        a[i]=false;
    for (int i=1;i<=10; i++)
    {
        cin>>n;
        a[n%42]=true;
    }
    for (int i=0;i<=42; i++)
    {
        if (a[i]==true) t++;
    }
    cout<<t;
    return 0;
}
