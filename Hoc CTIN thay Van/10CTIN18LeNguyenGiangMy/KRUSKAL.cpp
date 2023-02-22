#include <bits/stdc++.h>
using namespace std;
float kq;
typedef pair <float, pair <int,int>> edge;
vector <int> parent;
vector <edge> es;
void initset (int n)
{
    parent.assign (n,0);
    for (int i=0; i<n; i++)
        parent[i]=i;
}
int findset (int i)
{
    return (parent[i]==i)?i:(parent[i]=findset(parent[i]));
}
bool issameset (int i, int j)
{
    return findset(i)==findset(j);
}
void unionset (int i, int j)
{
    parent[findset(i)]=findset(j);
}
int n,m;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("KRUSKAL.INP","r",stdin);
    freopen("KRUSKAL.OUT","w",stdout);
    cin>>n>>m;
    es.resize(m);
    for (int i=0; i<m; i++)
        cin>>es[i].second.first>>es[i].second.second>>es[i].first;
    int u[200000], v[200000];
    initset(n);
    sort(es.begin(),es.end());
    kq=0.0;
    int dem=0;
    for (int i=0; i<m; i++)
    {
        edge e = es[i];
        if (!issameset(e.second.first, e.second.second))
        {
            kq+=e.first;
            dem+=1;
            u[dem]=e.second.first;
            v[dem]=e.second.second;
            unionset(e.second.first,e.second.second);
        }
    }
    cout<<fixed<<setprecision(2)<<kq<<"\n";
    for (int i=1; i<n; i++)
        cout<<u[i]<<" "<<v[i]<<"\n";
    return 0;
}
