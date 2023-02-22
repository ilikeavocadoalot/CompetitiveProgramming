#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long h,m,t;
    cin>>h>>m;
    t=m-45;
    if (t<0)
    {
        if(h-1>0)
        {
            h-=1;
            m=60+t;
        }
        else
        {
            h=h-1+24;
            m=60+t;
        }
    }
    else
    {
        m-=45;
    }
    cout<<h<<" "<<m;
    return 0;
}
