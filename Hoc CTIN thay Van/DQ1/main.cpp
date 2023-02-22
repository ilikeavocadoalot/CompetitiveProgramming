#include <bits/stdc++.h>
using namespace std;
long long int LuyThua (int x,int y)
{
    if (y==0) return 1;
    return x* LuyThua(x,y-1);
}
int main()
{
    freopen ("DQ1.INP","r",stdin);
    freopen ("DQ1.OUT","w",stdout);
    long long int x,y;
    cin>>x>>y;
    cout<<LuyThua(x,y);
    return 0;
}
