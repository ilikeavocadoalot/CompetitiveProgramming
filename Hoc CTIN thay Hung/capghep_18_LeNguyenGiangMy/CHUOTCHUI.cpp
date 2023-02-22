#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int maxn = 100;
int mark[maxn], lgh[maxn];
int n,m,s,v;
double gx[maxn],gy[maxn];
double hx[maxn],hy[maxn];
int g[maxn][maxn];

inline double ptd(double x, double y) {
    return sqrt(x*x +y*y);
}

inline bool thoat(int i, int j) {
    return 1.0*s*v>=ptd(gx[i]-hx[j],gy[i]-hy[j]);
}

bool dfs(int i) {
    for (int j = 0; j < m; j++)
        if (g[i][j]&&!mark[j]) {
            mark[j] = 1;
            if (lgh[j]==-1 || dfs(lgh[j])) {
                lgh[j]=i;
                return true;
            }
        }
    return false;
}

int max_match() {
    int mat = 0;
    memset(lgh, -1, sizeof (lgh));
    for (int i=0;i<n;i++) {
        memset(mark, 0, sizeof (mark));
        if (dfs(i)) mat++;
    } return mat;
}

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("chuotchui.inp","r",stdin);
    freopen("chuotchui.out","w",stdout);
    while (cin>>n>>m>>s>>v) {
        for (int i=0;i<n;i++) cin>>gx[i]>>gy[i];
        for (int i=0;i<m;i++) cin>>hx[i]>>hy[i];
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (thoat(i,j)) g[i][j]=1;
                else g[i][j]=0;
            }
        } cout<<n-max_match()<<"\n";
    }return 0;
}
