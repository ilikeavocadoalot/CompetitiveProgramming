#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("Tongvatrungbinhcong.inp","r",stdin);
    freopen("Tongvatrungbinhcong.out","w",stdout);
    long n,m,t;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        long tong=0;
        for (int j=1;j<=m;j++)
        {
            cin>>t;
            tong+=t;
        }
        printf("%d %.2f",tong,double(tong)/m);
        cout<<endl;
    }
    return 0;
}
