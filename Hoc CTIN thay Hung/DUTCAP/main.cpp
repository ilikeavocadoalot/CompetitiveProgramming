#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int maxn = 1e5+7;
int n,c,I,low[maxn],num[maxn],par[maxn],cnt,cntC[maxn],cntI[maxn],res;
int m;
vector<int> ptd[maxn];
bool isc[maxn],isi[maxn];
void dfs(int u){
    low[u]=num[u]=++cnt;
    for (int i=0;i<ptd[u].size();i++){
        int v=ptd[u][i];
        if (!par[v]){
            par[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            cntC[u] += cntC[v],cntI[u] += cntI[v];
            res+=(low[v]>num[u] && (cntC[v]==0 || cntC[v]==c) || cntI[v] == 0 || cntI[v] == I);
        } else if (par[u]!=v) low[u]=min(low[u],num[v]);
        if (isc[u]) ++cntC[u];
        if (isi[u]) ++cntI[u];
    }
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("DUTCAP.INP","r",stdin);
    freopen("DUTCAP.OUT","w",stdout);
    cin>>n>>m>>c>>I;
    for (int i=0;i<c;i++){
        int u;
        cin>>u,isc[u]=1;
    } for (int i=0;i<I;i++){
        int u;
        cin>>u,isi[u]=1;
    } for (int i = 0;i<=m;i++){
        int u,v;
        cin>>u>>v;
        ptd[u].push_back(v);
        ptd[v].push_back(u);
    }for (int u=1;u<=n;u++){
        if (par[u]) continue;
        par[u]=u;
        dfs(u);
    } cout<<res;

    return 0;
}
