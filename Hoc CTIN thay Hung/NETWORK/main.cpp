#include <bits/stdc++.h>
using namespace std;
const int m = 505;
int fa[m];
bool vis [m * m];
int s,p;
struct node {
    int u,v;
    double w;
}edge [m*m];
struct pt
{
    int x,y;
}pts[m];
double getdis (pt a, pt b)
{
    double num = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return (double) sqrt(num);
}
bool cmp (node a,node b)
{
    return a.w <b.w;
}
void init ()
{
    memset (vis,0,sizeof(vis));
    for (int i = 0; i<=p; i++)
    {
        fa[i]=i;
    }
}
int fin(int x)
{
    return x == fa[x] ? x : fa[x] = fin(fa[x]);
}
void kruskal (int m)
{
    for (int i=0; i<m; i++)
    {
        int x = edge[i].u, y = edge[i].v;
        int fx = fin(x), fy = fin(y);
        if (fx!=fy)
        {
            vis[i]=1;
            fa[fx]= fy;
        }
    }
}
int main()
{
    freopen("NETWORK.INP","r",stdin);
    freopen("NETWORK.OUT","w",stdout);
    cin>>s>>p;
    init();
    for (int i=0; i<p; i++)
        cin>>pts[i].x>>pts[i].y;
    int cnt=0;
    for (int i=0; i<p; i++)
    {
        for (int j=i+1; j<p; j++)
        {
            edge[cnt].u=i;
            edge[cnt].v=j;
            edge[cnt++].w=getdis(pts[i],pts[j]);
        }
    }
    sort(edge, edge+cnt, cmp);
    int m=p*(p-1)/2;
    kruskal(m);
    double ans=0;
    for (int i=m; i>=0; i--)
    {
        if (vis[i])
        {
            if (s>1) s--;
            else {ans = edge[i].w; break;}
        }
    }
    printf("%.2lf",ans);
    return 0;
}
