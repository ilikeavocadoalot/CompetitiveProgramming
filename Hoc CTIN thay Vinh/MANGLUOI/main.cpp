#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],v[1001],k,n,m,bfs;
int t1,t2;
void dfsngauchua (int u)
{
    for (int i=1; i<=n; i++)
        if (a[u][i]==1 && v[i]==0)
        {
            v[i]=bfs;
            dfsngauchua(i);
        }
}
int main()
{
    freopen ("MANGLUOI.INP","r",stdin);
    freopen ("MANGLUOI.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        cin>>t1>>t2;
        a[t1][t2] = 1;
        a[t2][t1] = 1;
    }
    for (bfs=1; bfs<=n; bfs++)
        dfsngauchua(bfs);
    for (int i=0; i<k; i++)
    {
        cin>>t1>>t2;
        if (v[t1]==v[t2]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
