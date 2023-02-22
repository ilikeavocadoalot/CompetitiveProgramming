#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],v[1001],k,m,dem=0;
void dfsngauchua (int u)
{
    for (int i=1; i<=m; i++)
        if (a[u][i] && !v[i])
        {
            v[i]=1;
            dfsngauchua(i);
        }
}
int main()
{
    freopen ("BUOCTHUYEN.INP","r",stdin);
    freopen ("BUOCTHUYEN.OUT","w",stdout);
    cin>>m>>k;
    for (int i=1; i<=k; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1][t2] = 1;
        a[t2][t1] = 1;
    }
    for (int i=1; i<=250; i++)
    {
        dfsngauchua(i);
        if (v[i]!=0) break;
    }
    for (int i=1; i<=m; i++)
        if (v[i]==0) dem++;
    if (dem==0) cout<<0<<endl;
    else
    {
        for (int i=1; i<=m; i++)
            if (v[i]==0) cout<<i<<endl;
    }
    return 0;
}
