#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9;
const int maxn = 300, maxe = 9010;

int src, snk, nNode, nEdge;
int Q[maxn], last_edge[maxn], pro[maxn], dist[maxn];
int flow[2*maxe],cap[2*maxe],prev_edge[2*maxe],to[2*maxe];

inline void init(int _src, int _snk, int _n){
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    memset(last_edge,-1,sizeof(last_edge));
}

inline void add_edge(int u, int v, int c, int bi = 1){
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[u], last_edge[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = bi == 1 ? c : 0, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[v], last_edge[v] = nEdge++;
}

bool bfs(){
    int st, en, i, u, v;
    memset(dist,-1,sizeof(dist));
    dist[src] = st = en = 0;
    Q[en++] = src;
    while (st < en){
        u = Q[st++];
        for (i = last_edge[u]; i >= 0; i = prev_edge[i]){
            v = to[i];
            if (flow[i] < cap[i] && dist[v] == -1){
                dist[v] = dist[u] + 1;
                Q[en++] = v;
            }
        }
    } return dist[snk] != -1;
}

int dfs(int u, int fl){
    if (u == snk) return fl;
    for (int &e = pro[u], v, df; e >= 0; e = prev_edge[e]){
        v = to[e];
        if (flow[e] < cap[e] && dist[v] == dist[u] + 1){
            df = dfs(v, min(cap[e] - flow[e], fl));
            if (df > 0){
                flow[e] += df;
                flow[e ^ 1] -= df;
                return df;
            }
        }
    }return 0;
}

int dinitz(){
    int ret = 0;
    int df;
    while (bfs()){
        for (int i = 1; i <= nNode; i++)
            pro[i] = last_edge[i];
        while (true)
        {
            df = dfs(src, inf);
            if (df)
                ret += (int)df;
            else
                break;
        }
    }
    return ret;
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("locdau.inp","r",stdin);
    freopen("locdau.out","w",stdout);
    int cs, t, i, j, k, x, y, z, ans, m, p, q, n;
    cin>>n;
    init(2 * n + 1, 2 * n + 2, 2 * n + 2);
    for (i = 1; i <= n; i++){
        cin>>x;
        add_edge(i, n + i, x);
    }cin>>m;
    for (i = 1; i <= m; i++){
        cin>>x>>y>>z;
        add_edge(x + n, y, z, 0);
    }cin>>p>>q;
    for (i = 1; i <= p; i++){
        cin>>x;
        add_edge(2 * n + 1, x, inf);
    }for (i = 1; i <= q; i++){
        cin>>x;
        add_edge(x + n, 2 * n + 2, inf);
    } cout<<dinitz();
    return 0;
}