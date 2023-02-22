#include <bits/stdc++.h>
int n,m,mi,a[10000][10000],d[10000][10000],si2,sj2,c[10000][10000];
int x[4]={-1,0,1,0};
int y[4]={0,-1,0,1};
bool kt=0;
using namespace std;
typedef pair <int,int> ii;
void tenlagidaynhi(int t1,int t2)
{
    queue <ii> q;
    q.push(ii(t1,t2));
    d[t1][t2]=0;
    while (!q.empty() && kt==0)
    {
        int ui=q.front().first;
        int uj=q.front().second;
        q.pop();
        for (int index=0; index<4; index++)
        {
            int vi=ui+x[index];
            int vj=uj+y[index];
            if (vi>0 && vi<=n && vj>0 && vj<=m)
            {
                if (a[vi][vj]==0 && c[vi][vj]==0)
                {
                    q.push(ii(vi,vj));
                    c[vi][vj]=1;
                    d[vi][vj]=d[ui][uj]+1;
                }
            }
            else
            {
                cout<<d[ui][uj];
                kt=1;
            }
        }
    }
}
int main()
{
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if (a[i][j]==2)
            {
                si2=i;
                sj2=j;
            }
        }
    tenlagidaynhi(si2,sj2);
    if (kt==0) cout<<-1<<"\n";
}
