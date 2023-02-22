#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000][10000],dem,k;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
typedef pair <int,int> ii;
int mlemmlem(int t1, int t2)
{
    queue <ii> q;
    q.push(ii(t1,t2));
    dem--;
    a[t1][t2]=0;
    while (!q.empty())
    {
        int ui=q.front().first;
        int uj=q.front().second;s
        q.pop();
        for (int i=0; i<4; i++)
        {
            int vi=ui+x[i];
            int vj=uj+y[i];
            if (vi>0 && vj>0 && vi<=n && vj<=m)
            {
                if (a[vi][vj]==1)
                {
                    q.push(ii(vi,vj));
                    dem--;
                    a[vi][vj]=0;
                }
            }
        }
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("BATTLESHIP.INP","r",stdin);
    freopen("BATTLESHIP.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if (a[i][j]==1) dem++;
        }
    for (int i=0; i<k; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        if (a[t1][t2]==0) cout<<dem<<"\n";
        else
        {
            mlemmlem(t1,t2);
            cout<<dem<<"\n";
        }
    }
    return 0;
}
