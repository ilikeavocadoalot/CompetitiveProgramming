#include <bits/stdc++.h>
using namespace std;
long long n,f[1000010];
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("11401.INP","r",stdin);
    freopen("11401.OUT","w",stdout);
    n=1;
    f[3]=0;
    f[4]=1;
    //chinh hop 2 cua n, n chap 2, thu gon thanh i*(i-1) tru cho ti le vang
    for (int i=5; i<=1000000; i++)
        f[i]=f[i-1]+(i*(i-1)-(i/2+1)*(i/2)-(i+1)*(i-(i/2+1)));
    while (true)
    {
        cin>>n;
        if (n<3) break;
        cout<<f[n]<<"\n";
    }
    return 0;
}
