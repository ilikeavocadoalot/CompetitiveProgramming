#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
const int maxn = 2e4;
const int inf = 1e7+7;
int low[maxn+7],num[maxn+7],bel[maxn+7],in[maxn+7],scc=0,timer=0;
int n,m;
vector<int> adj[maxn];
stack<int> st;

void dfs(int u){
    low[u]=num[u]=++timer;
    st.push(u);
    for (auto v: adj[u]){
        if (num[v])
            low[u]=min(low[u],num[v]);
        else{
            dfs(v);
            low[u]=min(low[u],low[v]);

        }
    }
    if (low[u]==num[u]){
        scc++;
        int v;
        do{
            v=st.top();
            st.pop();
            low[v]=num[v]=inf;
            bel[v]=scc;

        }while (u!=v);
    }
}
void compress(){
    memset(low,0,sizeof low);
    memset(num,0,sizeof num);
    memset(in,0,sizeof in);
    timer=scc=0;
    for (int i = 1 ;i<=n;i++)
        if (!num[i]) dfs(i);
    for (int u = 1 ;u<=n;u++)
        for (auto v: adj[u]){
            if (bel[u]!=bel[v]){
                in[bel[v]]++;
            }
    }
}
void solve(int test){
        cin>>n>>m;
        for (int i = 1 ;i<=10000;i++)
            adj[i].clear();
        for (int i = 1 ;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        int res=0;
        compress();
        for (int i=1;i<=scc;i++)
            if (in[i]==0)
             res++;
        cout<<"Case "<<test<<": "<<res<<"\n";
}
signed main(){
        cin.sync_with_stdio(false);
        cin.tie(0);
        freopen("11770.inp","r",stdin);
        freopen("11770.out","w",stdout);
        int t;
        cin>>t;
        for (int i = 1 ;i<=t;i++)
            solve(i);

}

