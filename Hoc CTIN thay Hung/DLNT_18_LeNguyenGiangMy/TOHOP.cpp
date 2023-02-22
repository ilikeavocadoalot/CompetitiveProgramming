#include <bits/stdc++.h>
using namespace std;
double kq;
int x,y,u,v,q,p,r,s;
void tru()
{
    while (y<=r || v<=q)
    {
        if (kq<100000000) break;
        if (y<=r) kq/=y,y++;
        if (kq<100000000) break;
        if (v<=q) kq/=v; v++;
    }
}
int main()
{
    freopen("TOHOP.INP","r",stdin);
    freopen("TOHOP.OUT","w",stdout);
    cin>>p>>q>>r>>s;
    x=p-q+1;
    y=r-s+1;
    u=2;
    v=2;
    kq=1;
    while (x<=p || u<=s)
    {
        if (x<=p) kq*=x,x++;
        if (kq>100000000) tru();
        if (u<=s) kq*=u,u++;
        if (kq>100000000) tru();
    }
    while (y<=r)
        kq/=y,y++;
    while (v<=q)
        kq/=v,v++;
    cout<<fixed<<setprecision(5)<<kq;
    return 0;
}
