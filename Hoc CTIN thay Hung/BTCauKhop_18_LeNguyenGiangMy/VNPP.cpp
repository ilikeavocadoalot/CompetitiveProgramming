#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
#define notTERMINAL true
#define intf "%d"

const int limit_n = 100;
vector<int> c[limit_n];

int dlow[limit_n], dnum[limit_n], dpar[limit_n], dpointTH=0, dchildTH=0, droot;
bool isChokePoint[limit_n];
void findBridge(int u) {
    dlow[u] = dnum[u] = ++dpointTH;
    for (int v : c[u]) {
        if (dnum[v] == 0) {
            dpar[v] = u; dchildTH+=(u==droot);
            findBridge(v);
            if (u != droot && dlow[v] >= dnum[u]) isChokePoint[u] = true;
            dlow[u] = min(dlow[u], dlow[v]);
        }
        else if (v!=dpar[u])
            dlow[u] = min(dlow[u], dnum[v]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if notTERMINAL
    freopen("VNPP.INP", "r", stdin);
    freopen("VNPP.OUT", "w", stdout);
#endif

    int n; while (cin >> n, n != 0) {
        string s;
        for (int i=0; i<limit_n; i++) c[i].clear();
        fill(dlow, dlow+limit_n, 0);
        fill(dnum, dnum+limit_n, 0);
        fill(dpar, dpar+limit_n, 0);
        while (getline(cin, s), s != "0") {
            stringstream ss(s); int u, v;
            ss >> u; while (ss >> v) {
                c[u].push_back(v);
                c[v].push_back(u);
            }
        }

        for (int i=1; i<=n; i++) {
            if (dnum[i] == 0) {
                droot=i, dchildTH=0;
                fill(isChokePoint, isChokePoint+limit_n, false);
                findBridge(droot); isChokePoint[droot]=(dchildTH>1);
            }
        }

        printf(intf "\n", count(isChokePoint, isChokePoint+limit_n, true));
    }
}