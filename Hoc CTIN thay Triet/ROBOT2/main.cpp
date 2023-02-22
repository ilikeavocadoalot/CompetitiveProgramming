#include <bits/stdc++.h>
using namespace std;
int n,m,p,t,qu,ma,si,sj,si2,sj2,si3,sj3,si1,sj1,tong=0;
char a[100][100];
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
bool kt=0;
typedef pair<int,int> ii;
void lieutoicoxongkhong (int t1, int t2, int t3, int t4)
{
    int d[100][100];
    queue <ii> q;
    q.push(ii(t1,t2));
    d[t1][t2]=0;
    while (!q.empty())
    {
        int ui= q.front().first;
        int uj= q.front().second;
        q.pop();
        for (int index=0; index < 4; index++)
        {
            int vi=ui+x[index];
            int vj=uj+y[index];
            if ((vi<=n) && (vi>0) && (vj<=m) && (vj>0))
            {
                if (a[vi][vj]!='#')
                {
                    q.push(ii(vi,vj));
                    if (a[vi][vj]=='K')
                    {
                        d[vi][vj]=d[ui][uj]+p+1;
                        tong+=d[vi][vj];
                        return;
                    }
                    if (a[vi][vj]=='V')
                        d[vi][vj]=d[ui][uj]+qu+1;
                    if (a[vi][vj]=='.')
                        d[vi][vj]=d[ui][uj]+1;
                }
                else
                {
                    if (t3==999999 && t4==999999)
                    {
                        tong +=d[ui][uj];
                        return;
                    }
                }
            }
        }
    }
}
int main()
{
    freopen ("ROBOT2.INP","r",stdin);
    freopen ("ROBOT2.OUT","w",stdout);
    cin>>n>>m>>p>>qu>>t;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='X')
            {
                si=i;
                sj=j;
            }
            if (a[i][j]=='K' && si1==0 && sj1==0)
            {
                si1=i;
                sj1=j;
            }
            else if (a[i][j]=='K' && si2==0 && sj2==0)
            {
                si2=i;
                sj2=j;
            }
            else if (a[i][j]=='K' && si3==0 && sj3==0)
            {
                si3=i;
                sj3=j;
            }
        }
    lieutoicoxongkhong(si,sj,0,0);
    lieutoicoxongkhong(si1,sj1,0,0);
    lieutoicoxongkhong(si2,sj2,0,0);
    lieutoicoxongkhong(si3,sj3,999999,999999);
    if (tong+t>ma) ma= tong+t; tong=0;
    /*lieutoicoxongkhong(si,sj,0,0); lieutoicoxongkhong(si2,sj2,0,0); lieutoicoxongkhong(si1,sj1,0,0); lieutoicoxongkhong(si3,sj3,999999,999999);
    if (tong+t>ma) ma= tong+t; tong=0;
    lieutoicoxongkhong(si1,sj1); lieutoicoxongkhong(si2,sj2); lieutoicoxongkhong(si1,sj1);
    if (tong+t>ma) ma= tong+t; tong=0;
    lieutoicoxongkhong(si1,sj1); lieutoicoxongkhong(si2,sj2); lieutoicoxongkhong(si1,sj1);
    if (tong+t>ma) ma= tong+t; tong=0;
    lieutoicoxongkhong(si2,sj2); lieutoicoxongkhong(si2,sj2); lieutoicoxongkhong(si1,sj1);
    if (tong+t>ma) ma= tong+t; tong=0;
    lieutoicoxongkhong(si2,sj2); lieutoicoxongkhong(si2,sj2); lieutoicoxongkhong(si1,sj1);
    if (tong+t>ma) ma= tong+t; tong=0;*/
    cout<<ma;
    return 0;
}
