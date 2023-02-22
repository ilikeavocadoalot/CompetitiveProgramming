#include <bits/stdc++.h>
using namespace std;
int a[100001];
typedef pair <long long int,long long int> ii;
#define fi first
#define se second
vector <int> v [100000];
int n,q,t;
int b[100001];
ii d[100001];
int bfs (int s,long long k)
{
    queue <int> qu;
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    long long int res=999999;
    qu.push(s);
    b[s]=1;
    d[s]={a[s],1};
    while (qu.size())
    {
        int u=qu.front();
        qu.pop();
        if (d[u].fi>=k)
        {
            res= min (res, d[u].se);
            continue;
        }
        for (int i=0; i<v[u].size(); i++)
        {
            int t=v[u][i];
            if (b[t]==0)
            {
                qu.push(t);
                b[t]=1;
                d[t]={d[u].fi+a[t],d[u].se+1};
            }
        }
    }
    return ((res==999999)?-1:res);
}
int main()
{
    freopen("TIMDUONG.INP","r",stdin);
    freopen("TIMDUONG.OUT","w",stdout);
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n-1; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    for (int i=1;i<=q;i++)
    {
        int x;
        long long k;
        cin>>x>>k;
        cout<<bfs(x,k)<<"\n";
    }
    return 0;
}
