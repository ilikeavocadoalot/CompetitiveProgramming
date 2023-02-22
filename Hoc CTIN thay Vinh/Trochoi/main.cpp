#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int n,m,c,mi=9999999,si,sj,ti,tj,l1,l2,l3,l4,k1i,k1j,k2i,k2j,l5,l6;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
int d[101][101];
typedef pair <int,int> ii;
void iuu (int si, int sj)
{
    queue <ii> q;
    memset(d,0,sizeof(d));
    d[si][sj]=0;
    q.push(ii(si,sj));
    while (!q.empty())
    {
        int ui=q.front().first;
        int uj=q.front().second;
        q.pop();
        for (int index=0; index<4; index++)
        {
            int vi=ui+x[index];
            int vj=uj+y[index];
            if (vi<=n && vj<=m && vi>0 && vj>0)
                if (a[vi][vj]!='#' && d[vi][vj]==0)
                {
                    q.push(ii(vi,vj));
                    d[vi][vj]=d[ui][uj]+1;
                }
        }
    }
}
int main()
{
    freopen("Trochoi.inp","r",stdin);
    freopen("Trochoi.out","w",stdout);
    cin>>n>>m>>c;
    if (c==1)
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                cin>>a[i][j];
                if (a[i][j]=='B')
                {
                    si=i;
                    sj=j;
                }
                if (a[i][j]=='C')
                {
                    ti=i;
                    tj=j;
                }
            }
        iuu(si,sj);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                if (a[i][j]=='K')
                    if (d[i][j]<mi) mi=d[i][j];
    }
    else
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                cin>>a[i][j];
                if (a[i][j]=='B')
                {
                    si=i;
                    sj=j;
                }
                if (a[i][j]=='C')
                {
                    ti=i;
                    tj=j;
                }
                if (a[i][j]=='K' && k1i==0)
                {
                    k1i=i;
                    k1j=j;
                }
                if (a[i][j]=='K' && k1i!=0)
                {
                    k2i=i;
                    k2j=j;
                }
            }
        iuu (k1i,k1j);
        l1=d[si][sj];
        l2=d[ti][tj];
        l3=d[k2i][k2j];
        iuu (k2i,k2j);
        l4=d[si][sj];
        l5=d[ti][tj];
        l6=d[k1i][k1j];
        if (l1+l6+l5<l4+l3+l2) mi=l1+l6+l5;
        else mi=l4+l3+l2;
    }
    cout<<mi;
    return 0;
}
