#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
const int inf = 1e9;
int w, h,n, ptd, lgh;
int  ansd[maxn], res[maxn] ,x[maxn], y[maxn];;
vector<int> e[maxn], c[maxn], f[maxn], p[maxn];

void add(int u, int v, int c1, int c2)
{
    if (u < 0)
        u = (u == -2) ? ptd : lgh;
    if (v < 0)
        v = (v == -2) ? ptd : lgh;
    e[u].push_back(v), c[u].push_back(c1), f[u].push_back(0);
    e[v].push_back(u), c[v].push_back(c2), f[v].push_back(0);
    p[u].push_back((int)(f[v].size()) - 1);
    p[v].push_back((int)(f[u].size())  - 1);
}

bool bfs()
{
    memset(ansd,-1,sizeof(ansd));
    ansd[ptd] = 0;
    int size_q = 0, q[maxn];
    q[size_q++] = ptd;
    for (int i = 0; i < size_q; i++)
    {
        int x = q[i];
        for (int j = 0; j < (int)(e[x].size()); j++)
        {
            if (f[x][j] < c[x][j] && ansd[e[x][j]] < 0)
            {
                q[size_q++] = e[x][j];
                ansd[e[x][j]] = ansd[x] + 1;
            }
        }
    }
    return (ansd[lgh] >= 0);
}
int dfs(int u, int b)
{
    if (u == lgh)
        return b;
    for (int &i = res[u]; i < (int)(e[u].size()); i++)
    {
        int _b = 0;
        if (f[u][i] < c[u][i] && ansd[e[u][i]] == ansd[u] + 1 && (_b = dfs(e[u][i], min(b, c[u][i] - f[u][i]))) > 0)
        {
            f[u][i] += _b;
            f[e[u][i]][p[u][i]] -= _b;
            return _b;
        }
    }
    return 0;
}
int flow()
{
    int ans = 0;
    while (bfs())
    {
        memset(res,0,sizeof(res));
        while (1)
        {
            int add = dfs(ptd, inf);
            if (add == 0)
                break;
            ans += add;
        }
    }
    return ans;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("vuotnguc.inp", "r", stdin);
    freopen("vuotnguc.out", "w", stdout);
    int n;
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    n = n+n;
    ptd = n, lgh = n + 1;
    for (int i = 0; i < n; i++){
        if (y[i] <= 100) add(-2, i, inf, 0);
        if (y[i] >= h - 100) add(i + n, -1, inf, 0);
        for (int j = i + 1; j < n; j++){
            if (abs(x[j] - x[i]) > 200 || abs(y[j] - y[i]) > 200) continue;
            if ((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) <= 40000){
                add(i + n, j, inf, 0);
                add(j + n, i, inf, 0);
            }
        } add(i, i + n, 1, 0);
    } cout << flow();
    return 0;
}
