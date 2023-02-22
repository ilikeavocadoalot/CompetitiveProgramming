#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000][10000],dem,k,c[10000][10000];
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
queue <int> p;
queue <int> q;
void mlemmlem(int t1, int t2)
{
    p.push(t1);
    q.push(t2);
    dem--;
    a[t1][t2]=0;
    c[t1][t2]=1;
    while (!p.empty())
    {
        int ui=p.front();
        int uj=q.front();
        p.pop();
        q.pop();
        for (int i=0; i<4; i++)
        {
            int vi=ui+x[i];
            int vj=uj+y[i];
            if (vi>0 && vj>0 && vi<=n && vj<=m)
            {
                if (c[vi][vj]==0 && a[vi][vj]==1)
                {
                    p.push(vi);
                    q.push(vj);
                    c[vi][vj]=1;
                    a[vi][vj]=0;
                    dem--;
                }
            }
            vi=ui-x[i];
            vj=uj-y[i];
        }
    }
}
int main()
{
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
        if (a[t1][t2]==0) cout<<dem<<endl;
        else
        {
            if (c[t1][t2]==0)
            {
                mlemmlem(t1,t2);
                cout<<dem<<endl;
            }
        }
    }
    return 0;
}
