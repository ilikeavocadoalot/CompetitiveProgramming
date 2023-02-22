#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6+15;
long long n, m, c, a[maxn];
deque <long long> pmin, pmax;
vector <long long> p;
signed main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("THUAM.INP", "r", stdin);
    freopen("THUAM.OUT", "w", stdout);
    cin >>n>>m>>c;
    for (long long i = 0; i < n; ++i)
        cin >> a[i];
    for (long long i = 0; i < n; ++i)
    {
        if (i >= m)
            while (!pmin.empty() && pmin.front() <= i - m)
                pmin.pop_front();
        if (i >= m)
            while (!pmax.empty() && pmax.front() <= i - m)
                pmax.pop_front();
        while (!pmin.empty() && a[pmin.back()] > a[i])
            pmin.pop_back();
        while (!pmax.empty() && a[pmax.back()] < a[i])
            pmax.pop_back();
        pmin.push_back(i);
        pmax.push_back(i);
        if (i < m - 1)
            continue;
        if (a[pmax.front()] - a[pmin.front()]<=c)
            p.push_back(i-m+2);
    }
    if (p.empty())
        cout << 0;
    else
        for (long long i = 0; i < (long long)p.size(); ++i)
            cout << p[i] << '\n';
}
