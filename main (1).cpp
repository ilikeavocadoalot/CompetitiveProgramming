#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define up(i, a, n) for (int i = a; i <= n; i++)
#define douwn(i, a, n) for (int i = a; i >= n; i--)
#define fi freopen("tamgiac.INP", "r", stdin)
#define fo freopen("tamgiac.OUT", "w", stdout)
#define pb push_back
#define fst first
#define sec second
#define emplace_back ep;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> qii;
typedef pair<qii, int> qqi;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
const int maxn = 2e2 + 5;
const int maxm = 2e6 + 5;
int n, res;
char c;
int h[maxn];
int a[maxn][maxn], p[maxn][maxn];
void solve1()
{
    int u = 1;
    up(j, 1, n * 2 - 1)
    {
        if (j % 2 == u && a[1][j])
            h[j] = 1;
    }
    up(i, 2, n)
    {
        up(j, 1, (n - i + 1) * 2 - 1)
        {
            if (j % 2 == u && a[i][j])
            {
                if (p[i - 1][j + 2] - p[i - 1][j - 1] == 3)
                    h[j] = min(h[j], h[j + 2]) + 1;
                else
                    h[j] = 1;
            }
            else
                h[j] = 0;
            if (res < h[j])
                res = h[j];
        }
    }
}
void solve2()
{
    int u = 0;
    up(i, 1, n * 2 - 1) h[i] = 0;
    douwn(i, n - 1, 1)
    {
        up(j, 1, (n - i + 1) * 2 - 1)
        {
            if (j % 2 == u && a[i][j])
            {
                if (p[i + 1][j] - p[i + 1][j - 3] == 3)
                    h[j] = min(h[j], h[j - 2]) + 1;
                else
                    h[j] = 1;
            }
            else
                h[j] = 0;
            if (res < h[j])
                res = h[j];
        }
    }
}
int main()
{
    fi;
    fo;
    cin >> n;
    up(i, 1, n)
    {
        up(j, 1, 200) a[i][j] = 0;
    }
    up(i, 1, n)
    {
        int cnt = (n - i + 1) * 2 - 1;
        up(j, 1, cnt)
        {
            // cout<<cnt<<' ';
            cin >> c;
            a[i][j] = (c == '#' ? 0 : 1);
            // cout<<a[i][j]<<" \n"[j==cnt];
        }
    }
    up(i, 1, n)
    {
        int cnt = (n - i + 1) * 2 - 1;
        up(j, 1, cnt)
        {

            if (a[i][j])
                p[i][j] = p[i][j - 1] + a[i][j];
            else
                p[i][j] = 0;
            // cout<<p[i][j]<<" \n"[j==cnt];
        }
    }
    solve1();
    solve2();
    cout << 1ll * res * res;
}