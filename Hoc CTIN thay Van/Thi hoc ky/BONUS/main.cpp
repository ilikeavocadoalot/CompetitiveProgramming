#include <iostream>
using namespace std;
int n,p,kq,so,r,l;
int main()
{
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin>>n>>p;
    for (int i=1;i<=n;i++)
    {
        cin>>so;
        if (i<p) l+=so;
        else if (i>p) r+=so;
        else kq=so;
    }
    if (n-p<p-1) kq+=(n-p)*2+r+p-1+l;
    else kq+=(p-1)*2+r+l+n-p;
    cout<<kq;
    return 0;
}
