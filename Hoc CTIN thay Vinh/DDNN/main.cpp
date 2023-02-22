#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int a[310][310],d[310][310],check[310][310],si,sj,n,m,k,mi=999999;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
char table [310][310];
void dijkstra (int si, int sj)
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            d[i][j]=999999;
            check[i][j]=0;
        }
    priority_queue <iii, vector <iii>, greater <iii>> pq;
    d[si][sj]=0;
    pq.push(iii(d[si][sj],ii(si,sj)));
    while (!pq.empty())
    {
        int ui=pq.top().second.first;
        int uj=pq.top().second.second;
        pq.pop();
        if (check[ui][uj]) continue;
        check [ui][uj]=1;
        for (int k=0; k<4; k++)
        {
            int vi=ui+x[k];
            int vj=uj+y[k];
            int we=a[vi][vj];
            if (d[vi][vj]>d[ui][uj]+we)
            {
                d[vi][vj]=d[ui][uj]+we;
                pq.push(iii(d[vi][vj],ii(vi,vj)));
            }
        }
    }
}
int main()
{
    freopen("MECUNG.INP","r",stdin);
    freopen("MECUNG.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>table[i][j];
            if (table[i][j]=='A')
            {
                si=i;
                sj=j;
            }
            else if (table[i][j]=='C') a[i][j]=1+k;
            else if (table[i][j]=='.') a[i][j]=1;
            else a[i][j]=9999999;
        }
    dijkstra(si,sj);
    for (int i=1; i<=m; i++)
        if (d[1][i]<mi) mi=d[1][i];
    for (int i=1; i<=m; i++)
        if (d[n][i]<mi) mi=d[n][i];
    for (int i=2; i<=n; i++)
        if (d[i][1]<mi) mi=d[i][1];
    for (int i=2; i<=n; i++)
        if (d[i][m]<mi) mi=d[i][m];
    cout<<mi+1;
    return 0;
}
