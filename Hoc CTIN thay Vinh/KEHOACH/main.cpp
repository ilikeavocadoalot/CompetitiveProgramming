#include <bits/stdc++.h>
using namespace std;
int a[1000][1000],v[1000],k,n,m,b[1000],c[1000],dem=0;
int t1,t2;
void dfsngauchua (int u)
{
    v[u]=1;
    c[u]++;
    for (int i=1; i<=n; i++)
        if (a[u][i] && !v[i])
            dfsngauchua(i);
}
int main()
{
    freopen ("KEHOACH.INP","r",stdin);
    freopen ("KEHOACH.OUT","w",stdout);
    cin>>k>>n>>m;
    for (int i=0; i<k; i++)
        cin>>b[i];
    for (int i=1; i<=m; i++)
    {
        cin>>t1>>t2;
        a[t1][t2] = 1;
    }
    for (int i=0; i<k; i++)
    {
        for (int j=0; j<=n; j++) v[j]=0;
        dfsngauchua(b[i]);
    }
    for (int i=1; i<=n; i++)
        if (c[i]==k) dem++;
    cout<<dem<<endl;
    return 0;
}
