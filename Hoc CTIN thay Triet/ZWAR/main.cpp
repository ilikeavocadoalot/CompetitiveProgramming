#include <bits/stdc++.h>
#include <memory.h>
using namespace std;
int n,m,t,hello,ma=0;
string a[1000];
typedef pair <int,int> ii;
int x[8]={-1,0,1,0,1,1,-1,-1};
int y[8]={0,-2,0,2,2,-2,2,-2};
int tenratladacsac (int t1, int t2)
{
    queue <ii> q;
    int dem=1;
    q.push(ii(t1,t2));
    a[t1][t2]='0';
    while(!q.empty())
    {
        int ui=q.front().first;
        int uj=q.front().second;
        q.pop();
        for (int k=0; k<8; k++)
        {
            int vi=ui+x[k];
            int vj=uj+y[k];
            if (vi>0 && vj>=0 && vi<=n && vj<=m && a[vi][vj]=='1')
            {
                q.push(ii(vi,vj));
                dem++;
                a[vi][vj]='0';
            }
        }
    }
    return (dem);
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("ZWAR.INP","r",stdin);
    freopen("ZWAR.OUT","w",stdout);
    cin>>t;
    for (int tt=0; tt<t; tt++)
    {
        cin>>n>>m;
        for (int i=0; i<=n; i++)
            getline(cin,a[i]);
        m=a[1].length()-1;
        for (int i=1; i<=n; i++)
            for (int j=0; j<=m; j++)
                if (a[i][j]=='1')
                {
                    hello++;
                    int tuiquaurr = tenratladacsac(i,j);
                    if (tuiquaurr > ma) ma=tuiquaurr;
                }
        cout<<hello<<" "<<ma<<"\n";
        ma=0;
        hello=0;
    }
    return 0;
}
