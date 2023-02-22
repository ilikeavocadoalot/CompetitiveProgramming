#include <bits/stdc++.h>
using namespace std;
int a[10000][10000],b[10000],cuoi[10000],d[10000],visit[10000],x[10000],c[10000],n,m,p,k,mi=999999;
typedef pair <int,int> ii;
void goi (int s)
{
    b[s]++;
    for (int u=1; u<=m; u++)
    {
        visit[u]=0;
        d[u]=0;
    }
    queue <int> q;
    q.push(s);
    visit[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int v=1; v<=m; v++)
        {
            if (a[u][v]==1 && visit[v]==0 && c[v]==0)
            {
                q.push(v);
                b[v]++;
                d[v]=d[u]+1;
                visit[v]=1;
            }
        }
    }
}
int main()
{
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    cin>>m>>n>>k>>p;
    for (int i=0; i<p; i++)
        cin>>x[i];
    for (int i=0; i<n; i++)
    {
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        if (t3==1)
        {
            a[t1][t2]=1;
            a[t2][t1]=1;
        }
        else
        {
            a[t1][t2]=0;
            a[t2][t1]=0;
        }
    }
    for (int i=0; i<k; i++)
    {
        int t;
        cin>>t;
        c[t]=1;
    }
    for (int i=0; i<p; i++)
    {
        goi(x[i]);
        for (int i=1; i<=m; i++)
            cuoi[i]=cuoi[i]+d[i];
    }
    for (int i=1; i<=m; i++)
        if (b[i]==p)
            if (cuoi[i]<mi) mi=cuoi[i];
    cout<<mi;
    return 0;
}
