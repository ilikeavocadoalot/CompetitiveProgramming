#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a1,a2,b1,b2,c1,c2,d1,d2;
    cin>>a1>>b1>>a2>>b2;
    cin>>c1>>d1>>c2>>d2;
    int t1,t2;
    t1=a1+b1+a2+b2;
    t2=c1+d1+c2+d2;
    if (t1<t2) cout<<"Emma"<<endl;
    else if (t1>t2) cout<<"Gunnar"<<endl;
    else cout<<"Tie"<<endl;
    return 0;
}
