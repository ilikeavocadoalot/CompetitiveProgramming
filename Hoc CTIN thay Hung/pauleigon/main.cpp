#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long n,p,q;
    cin>>n>>p>>q;
    if (((p+q)/n)%2==0) cout<<"paul";
    else cout<<"opponent";
    return 0;
}
