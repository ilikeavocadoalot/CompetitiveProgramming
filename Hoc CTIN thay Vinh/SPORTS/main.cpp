#include <bits/stdc++.h>
using namespace std;
int n,m,dem,a[10000][10000],f[10000],b[10000],low[10000],k,component=0;
stack <int> s;
void lamlelelen(int u)
{
    dem++;
    b[u]=dem;
    low[u]=b[u];
    s.push(u);
    for (int v=1;v<=n;v++)
    {
        if (f[v]==1 && a[u][v]>=k)
        {
            if(b[v]!=0)
                low[u]=min(low[u],b[v]);
			else
            {
				lamlelelen(v);
				low[u]=min(low[u],low[v]);
			}
        }
    }
    if (low[u]==b[u])
    {
        component++;
        int v;
        do
        {
            v =s.top();
            s.pop();
            f[v]=0;
        } while(v!=u);
    }
}
int main()
{
    freopen("SPORTS.INP","r",stdin);
    freopen("SPORTS.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=0; i<m; i++)
    {
        int t1,t2,mass;
        cin>>t1>>t2>>mass;
        if (a[t1][t2]!=0)
        {
            if (a[t1][t2]<mass)
                a[t1][t2]=mass;
        }
        else
            a[t1][t2]=mass;
    }
    for (int i=1; i<=n; i++)
    {
        f[i]=1;
        b[i]=0;
    }
    for (int i=1; i<=n; i++)
        if (b[i]==0)
            lamlelelen(i);
    cout<<component;
    return 0;
}
