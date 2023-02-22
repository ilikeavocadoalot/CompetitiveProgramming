#include <bits/stdc++.h>
using namespace std;
int n,k,b[100000],d[100000],x[3];
queue <int> q;
int toisedoiten (int u)
{
    q.push(u);
    d[u]=0;
    b[u]=1;
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        if (b[k]==1) return d[k];
        x[0]=v+1;
        x[1]=v-1;
        x[2]=v*2;
        for (int i=0; i<3; i++)
        {
            int t=x[i];
            if (t>=0 && t<=100000 && b[t]==0)
            {
                q.push(t);
                d[t]=d[v]+1;
                b[t]=1;
            }
        }
    }
}
int main()
{
    freopen("CUUHOA.INP","r",stdin);
    freopen("CUUHOA.OUT","w",stdout);
    cin>>n>>k;
    cout<<toisedoiten(n);
    return 0;
}
