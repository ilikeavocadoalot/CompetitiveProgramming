#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
const int maxn = 8001;

int n, day[maxn], cnt[maxn];
vector <int> ad[maxn];
queue <int> bfs;

void BFS(const int st) {
	day[st] = 0;
	bfs.push(st);

	while (!bfs.empty()) {
		int u = bfs.front(); bfs.pop();
		++cnt[day[u]];

		for (int i = 0; i < ad[u].size(); i++) {
			int v = ad[u][i];
			if (day[v] != -1) continue;
			day[v] = day[u] + 1;
			bfs.push(v);
		}
	}
}

signed main() {
    cin.sync_with_stdio(0);
	cin.tie(0);
	freopen("loantin.inp", "r", stdin);
	freopen("loantin.out", "w", stdout);
    cin >> n;
	for (int u = 0, m, v; u < n; u++) {
		cin >> m;
		while (m--) {
			cin >> v;
			ad[u].push_back(v);
		}
	} int t; cin >> t;
	while (t--) {
        int st; cin >> st;
        if (ad[st].empty()) {
            cout << "0\n";
            continue;
        } fill(day, day + n, -1);
        fill(cnt, cnt + n,  0);
        BFS(st);
        int res = max_element(cnt, cnt + n) - cnt;
        cout << cnt[res] << ' ' << res << '\n';
    }
}
