#include <bits/stdc++.h>
using namespace std;
int a[10000][10000],n,m,d[10000][10000],c[10000][10000];
int si1,si2,sj1,sj2;
int x[8]={-1,0,1,0,1,1,-1,-1};
int y[8]={0,-1,0,1,1,-1,1,-1};
queue <int> p;
queue <int> q;
int tuisekhonglamqualau (int t1,int t2,int t)
{
    if (a[t1][t2]!=t) return 1;
    d[t1][t2]=0;
    c[t1][t2]=1;
    p.push(t1);
    q.push(t2);
    if (t==1)
    {
        if (t1!=0) return 1;
    }
    else
    {
        if (t2!=0) return 1;
    }
    while (!p.empty())
    {
        int ui = p.front();
        int uj = q.front();
        p.pop();
        q.pop();
        for (int i=0; i<8; i++)
        {
            int vi=ui+x[i];
            int vj=uj+y[i];
            if (vi>=0 && vj>=0 && vi<n && vj<n)
            {
                if (a[vi][vj]==t && c[vi][vj]==0)
                {
                    p.push(vi);
                    q.push(vj);
                    d[vi][vj]= d[ui][uj]+1;
                    c[vi][vj]=1;
                    if (a[vi][vj]==1)
                    {
                        if (vi==n-1) return 0;
                    }
                    else if (a[vi][vj]==2)
                    {
                        if (vj==n-1) return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int main()
{
    freopen("CTMATRIX.INP","r",stdin);
    freopen("CTMATRIX.OUT","w",stdout);
    cin>>n;
    bool kt1=false,kt2=false;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin>>a[i][j];
    for (int i=0; i<n; i++)
        if (a[0][i]==1 && kt1!=true)
        {
            si1=0;
            sj1=i;
            if (tuisekhonglamqualau(si1,sj1,1)==0)
            {
                kt1=true;
                break;
            }
        }
    for (int i=0; i<n; i++)
        if (a[i][0]==2 && kt2!=true)
        {
            si2=i;
            sj2=0;
            if (tuisekhonglamqualau(si2,sj2,2)==0)
            {
                kt2=true;
                break;
            }
        }
    if (kt1==true && kt2==true) cout<<3<<endl;
    else if (kt1==true) cout<<1<<endl;
    else if (kt2==true) cout<<2<<endl;
    else cout<<0<<endl;
    return 0;
}
