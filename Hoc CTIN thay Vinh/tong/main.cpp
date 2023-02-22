#include <iostream>
#include <stdio.h>
int kq=0;
using namespace std;
int tong(int n)
{
    if (n==1) return 1;
    else return n+(tong(n-1));
}
void tong2(int n)
{
    if (n==1) kq=1;
    else
    {
        tong2(n-1);
        kq=kq+n;
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<tong(n)<<endl;
    tong2(n);
    cout<<kq;
    return 0;
}
