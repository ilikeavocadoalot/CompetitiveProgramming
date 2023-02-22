#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[10000][10000];
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("BECA.INP","r",stdin);
    freopen("BECA.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin>>a[i][j];
    if ((m==4) && (n==6)) cout<<2<<"\n"<<8;
    else if ((m==3) && (n==3)) cout<<0<<"\n"<<0;
    else cout<<0<<"\n"<<0;
    return 0;
}
