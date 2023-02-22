#include <bits/stdc++.h>
using namespace std;
int a[100],t;
int main()
{
    freopen("10882.INP","r",stdin);
    freopen("10882.OUT","w",stdout);
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        int x,y,z;
        x=y=z=0;
        cin>>a[1]>>a[2]>>a[3];
        sort (a+1,a+4);
        x = a[2]+a[3]-100;
        if (x<0) x=0;
        y= 100 - (a[2]+a[3]);
        if (y<0) y=0;
        z=a[1]-x-y;
        if (z<0) z=0;
        cout <<"Case #"<<i<<": ";
        if (x>a[1]) cout<<"The records are faulty.";
        else cout<<"Between "<<x+(z+1)/2<<" and "<<a[1]<<" times.";
        cout<<"\n";
    }
    return 0;
}
