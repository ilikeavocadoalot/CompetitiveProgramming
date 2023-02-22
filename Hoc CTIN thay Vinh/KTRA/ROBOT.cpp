#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
char a[1010][1010];
int d[1010][1010];
int x[]={0,-1,0,1};
int y[]={-1,0,1,0};
int n,m;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
bool inside (ii v)
{
    return (v.first>=1 && v.first<=n && v.second>=1 && v.second<=m);
}
int val (char tam)
{
    if (tam=='A' || tam=='K')
        return 0;
    if (tam=='B')
        return 1;
    if (tam=='C')
        return 2;
    if (tam=='D')
        return 3;
    if (tam=='E')
        return 7;
    if (tam=='F')
        return 8;
    if (tam=='G')
        return 6;
    if (tam=='H')
        return 7;
    if (tam=='I')
        return 8;
    if (tam=='J')
        return 9;
}
void dks (ii s)
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            d[i][j]=oo;
    priority_queue <iii, vector <iii>, greater <iii>> pq;
    pq.push({d[s.first][s.second]=val(a[s.first][s.second]),s});
    while (pq.size())
    {
        ii u = pq.top().second;
        int enough = pq.top().first;
        pq.pop();
        if (enough!=d[u.first][u.second]) continue;
        char gt1 = a[u.first][u.second];
        for (int k=0; k<=3; k++)
        {
            ii v = {u.first+x[k],u.second+y[k]};
            char gt2 = a[v.first][v.second];
            if (!inside(v)) continue;
            if (k==0)
            {
                if (gt1=='A') continue;
                if ((gt1=='B')&&(gt2=='A' || gt2=='D' || gt2=='H' || gt2=='I'|| gt2=='K')) continue;
                if ((gt1=='C')&&(gt2=='A'||gt2=='E'||gt2=='I'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='D')&&(gt2=='A'||gt2=='I'||gt2=='K')) continue;
                if ((gt1=='E')&&(gt2=='A'||gt2=='I'||gt2=='K')) continue;
                if ((gt1=='F')&&(gt2=='A'||gt2=='I'||gt2=='K')) continue;
                if ((gt1=='G')) continue;
                if ((gt1=='H')&&(gt2=='A'||gt2=='E'||gt2=='I'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='I')&&(gt2=='A'||gt2=='I'||gt2=='K')) continue;
                if ((gt1=='J')&&(gt2=='A'||gt2=='D'||gt2=='H'||gt2=='I'||gt2=='K')) continue;
                if ((gt1=='K')) continue;
                if (enough+val(gt2)<d[v.first][v.second])
                    pq.push({d[v.first][v.second]=enough+val(gt2),v});
            }
            if (k==1)
            {
                if (gt1=='A') continue;
                if ((gt1=='B')&&(gt2=='A'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='C')&&(gt2=='A'||gt2=='E'||gt2=='I'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='D')&&(gt2=='A'||gt2=='B'||gt2=='G'||gt2=='J')) continue;
                if ((gt1=='E')&&(gt2=='A'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='F')&&(gt2=='A'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='G')&&(gt2=='A'||gt2=='E'||gt2=='I'||gt2=='J'||gt2=='K')) continue;
                if (gt1=='H') continue;
                if ((gt1=='I')&&(gt2=='A'||gt2=='B'||gt2=='J'||gt2=='G'||gt2=='K')) continue;
                if ((gt1=='J')&&(gt2=='A'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='K')) continue;
                if (enough+val(gt2)<d[v.first][v.second])
                    pq.push({d[v.first][v.second]=enough+val(gt2),v});
            }
            if (k==2)
            {
                if (gt1=='A') continue;
                if ((gt1=='B')&&(gt2=='A'||gt2=='G'||gt2=='K')) continue;
                if ((gt1=='C')&&(gt2=='A'||gt2=='B'||gt2=='G'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='D')&&(gt2=='A'||gt2=='G'||gt2=='K')) continue;
                if ((gt1=='E')&&(gt2=='A'||gt2=='C'||gt2=='G'||gt2=='H'||gt2=='K')) continue;
                if ((gt1=='F')&&(gt2=='A'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='G')&&(gt2=='A'||gt2=='G'||gt2=='K')) continue;
                if ((gt1=='H')&&(gt2=='A'||gt2=='B'||gt2=='G'||gt2=='J'||gt2=='K')) continue;
                if ((gt1=='I')) continue;
                if ((gt1=='J')&&(gt2=='A'||gt2=='C'||gt2=='G'||gt2=='H'||gt2=='K')) continue;
                if ((gt1=='K')) continue;
                if (enough+val(gt2)<d[v.first][v.second])
                    pq.push({d[v.first][v.second]=enough+val(gt2),v});
            }
            if (k==3)
            {
                if (gt1=='A') continue;
                if ((gt1=='B')&&(gt2=='A'||gt2=='D'||gt2=='K'||gt2=='H'||gt2=='I')) continue;
                if ((gt1=='C')&&(gt2=='A'||gt2=='H'||gt2=='K')) continue;
                if ((gt1=='D')&&(gt2=='A'||gt2=='H'||gt2=='K')) continue;
                if ((gt1=='E')&&(gt2=='A'||gt2=='C'||gt2=='G'||gt2=='H'||gt2=='K')) continue;
                if ((gt1=='F')&&(gt2=='A'||gt2=='H'||gt2=='K')) continue;
                if ((gt1=='G')&&(gt2=='A'||gt2=='E'||gt2=='K'||gt2=='I'||gt2=='J')) continue;
                if ((gt1=='H')&&(gt2=='A'||gt2=='H'||gt2=='K')) continue;
                if ((gt1=='I')&&(gt2=='A'||gt2=='C'||gt2=='G'||gt2=='H'||gt2=='K')) continue;
                if ((gt1=='J')) continue;
                if ((gt1=='K')) continue;
                if (enough+val(gt2)<d[v.first][v.second])
                   pq.push({d[v.first][v.second]=enough+val(gt2),v});

            }
        }
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    int x1,x2,y1,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    dks({x1,y1});
    cout<<d[x2][y2];
    return 0;
}
