#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
int n,m,u,v,k,t,dem;
int d[100001],low[100001],number[100001];
vector <int> a[100001];
bool vi [100001];
void visit(int u,int p)
{
    number[u]=low[u]=++dem;
    for(int x:a[u])
    {
        if(x==p) continue;
        if(number[x])
            low[u]=min(number[x],low[u]);
        else
        {
            visit(x,u);
            low[u]=min(low[u],low[x]);
        }
    }
}
void dfs()
{
    memset(vi,true,sizeof(vi));
    queue <int> q;
    q.push(n);
    vi[n]=false;
    d[n]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int x:a[u])
        {
            if(vi[x])
            {
                d[x]=d[u];
                if(low[x]>=number[x]) d[x]++;
                q.push(x);
                vi[x]=false;
            }
        }
    }
}
int main(){
    freopen("FREQPATH.INP","r",stdin);
    freopen("FREQPATH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1; i<=m; i++) 
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    visit(n,0);
    dfs();
    cin>>t;
    for (int i=1; i<=t; i++) 
    {
        cin>>u;
        cout<<d[u]<<'\n';
    }
}
