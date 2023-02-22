#include <bits/stdc++.h>
#include <queue>
using namespace std;
int a[10000][10000],d[10000][10000],b[10000][10000];
bool c[10000][10000];
int si2,sj2,si3,k,sj3,si4,sj4,t;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
queue <int> p;
queue <int> q;
int n,m,tong;
void aicungluykecatoi (int t1,int t2)
{
    p.push(t1);
    q.push(t2);
    d[t1][t2]=0;
    c[t1][t2]=1;
    while (!p.empty())
    {
        int ui=p.front();
        int uj=q.front();
        q.pop();
        p.pop();
        for (int i=0; i<4; i++)
        {
            int vi=ui+x[i];
            int vj=uj+y[i];
            if ((vi>=0) && (vj>=0) && (vi<n) &&(vj<m))
            {
                if (c[vi][vj]==0 && a[vi][vj]!=1)
                {
                    p.push(vi);
                    q.push(vj);
                    d[vi][vj]= d[ui][uj]+1;
                    if (a[vi][vj]==3) t=d[vi][vj];
                    c[vi][vj]=1;
                }
            }
        }
    }
}
int main()
{
    freopen("RBGH.INP","r",stdin);
    freopen("RBGH.OUT","w",stdout);
    cin>>m>>n;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin>>a[i][j];
            if (a[i][j]==2)
            {
                si2=i;
                sj2=j;
            }
            if (a[i][j]==3)
            {
                si3=i;
                sj3=j;
            }
        }
    aicungluykecatoi(si2,sj2);
    tong=9999999;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i][j]==4)
            {
                b[i][j]=d[i][j];
                if (b[i][j]<tong) tong=b[i][j];
            }
    cout<<tong<<endl;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            d[i][j]=0;
            c[i][j]=0;
        }
    aicungluykecatoi(si3,sj3);
    tong=9999999;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            if (a[i][j]==4 && b[i][j]!=0)
            {
                b[i][j]+=d[i][j];
                if (b[i][j]<tong) tong=b[i][j];
            }
        }
    cout<<tong+t<<endl;
    return 0;
}
