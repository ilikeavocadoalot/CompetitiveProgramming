#include <bits/stdc++.h>
using namespace std;
int m, kq;
vector <int> a[100010];
int f[100010], g[100010], b[100010];
string s;
void dfs(int v, int pV)
{
    vector <int> fv;
    for (auto u: a[v])
    {
        if(u == pV) continue;
        dfs(u, v);
        fv.push_back(f[u]);
    }
    sort(fv.begin(),fv.end());
    f[v] = b[v];
    if(not fv.empty()) f[v] += fv.back();
    if(fv.size()>=2)
        g[v] = b[v] + fv.back() + fv[fv.size()-2];
    kq = max(kq, max(f[v], g[v]));
}
int main()
{
    freopen("KHOBAU.INP","r",stdin);
    freopen("KHOBAU.OUT","w",stdout);
    cin>>m;
    cin>>s;
    for (int i=0; i<s.size(); i++)
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                b[i+1]=1;
    for (int i=1; i<m; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1].push_back(t2);
        a[t2].push_back(t1);
    }
    dfs(1,0);
    if (kq!=0) cout<<kq;
    return 0;
}
