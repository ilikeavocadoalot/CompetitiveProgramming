#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int x[4]={1,0,0,-1};
int y[4]={0,-1,1,0};
char dd[4]={'D','L','R','U'};
char a[2000][2000];
int b[2000][2000];
string d[2000][2000];
typedef pair <int,int> ii;
void aidadattenchodongcode(int t1,int t2,int t3,int t4)
{
    queue <ii> q;
    memset(b,0,sizeof(b));
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            d[i][j]="";
    q.push(ii(t1,t2));
    b[t1][t2]=1;
    while (!q.empty())
    {
        int ui=q.front().first;
        int uj=q.front().second;
        q.pop();
        for (int index=0; index<4; index++)
        {
            int vi=ui+x[index];
            int vj=uj+y[index];
            if (vi>=1 && vj>=1 && vi<=n && vj<=m)
            {
                if (a[vi][vj]=='.' && b[vi][vj]==0)
                {
                    q.push(ii(vi,vj));
                    b[vi][vj]=1;
                    d[vi][vj]=d[ui][uj]+dd[index];
                    if (vi==t3 && vj==t4)
                    {
                        cout<<d[vi][vj]<<"\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"Impossible"<<"\n";
}
int main()
{
    freopen("ROBOT3.INP","r",stdin);
    freopen("ROBOT3.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    cin>>t;
    for (int i=0; i<t; i++)
    {
        int xdau,ydau,xcuoi,ycuoi;
        cin>>xdau>>ydau>>xcuoi>>ycuoi;
        aidadattenchodongcode(xdau,ydau,xcuoi,ycuoi);
    }
    return 0;
}
