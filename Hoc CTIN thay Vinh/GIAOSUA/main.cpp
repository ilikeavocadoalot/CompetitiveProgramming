#include <bits/stdc++.h>
using namespace std;
int a[1000][1000],dem,b[1000],n,m,k;
int lailamotcaidfs(int u)
{
    b[u]=1;
    for (int v=1; v<=n; v++)
        if (a[u][v]>=k && b[v]==0)
            lailamotcaidfs(v);
}
int main()
{
    freopen("GIAOSUA.INP","r",stdin);
    freopen("GIAOSUA.OUT","w",stdout);
    cin >>n>>m>>k;
    for (int i=0; i<m; i++)
    {
        int t1,t2,mass;
        cin>>t1>>t2>>mass;
        if (a[t1][t2]!=0)
        {
            if (a[t1][t2]<mass)
            {
                a[t1][t2]=mass;
                a[t2][t1]=mass;
            }
        }
        else
        {
            a[t1][t2]=mass;
            a[t2][t1]=mass;
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (b[i]==0)
        {
            lailamotcaidfs(i);
            dem++;
        }
    }
    cout<<dem<<"\n";
    return 0;
}
