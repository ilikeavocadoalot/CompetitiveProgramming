#include <bits/stdc++.h>
#include <queue>
using namespace std;
long long int m,n,t1,t2,t,x,y,d[10000],b[10000];
long long int a[10000][10000];
void toikhongkiproi(long long int s)
{
    queue<long long int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1;v<=n;v++)
        {
            if (a[u][v] && d[v]==0)
            {
                q.push(v);
                d[v]=u;
            }
            if (d[y]!=0) return;
        }
    }
}
int main()
{
    freopen("DULICH.INP","r",stdin);
    freopen("DULICH.OUT","w",stdout);
    cin>>m>>n>>t1>>t2;
    for (int i=1; i<=m; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1][t2]=1;
        a[t2][t1]=1;
    }
    cin>>x>>y;
    toikhongkiproi(x);
    while (y!=x)
    {
        t++;
        b[t]=y;
        y=d[y];
    }
    cout<<t+1<<endl;
    cout<<x<<" ";
    for (int i=t; i>0; i--)
        cout<<b[i]<<" ";
    return 0;
}
