#include <bits/stdc++.h>
using namespace std;
int n,m,d,k,kq;
int main()
{
    freopen("HAINAM.INP","r",stdin);
    freopen("HAINAM.OUT","w",stdout);
    cin>>n>>m>>d>>k;
    char a[n+5][m+5];
    int p[n+5][m+5];
    memset(p,0,sizeof(p));
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='S') p[i][j]++;
            p[i][j]+=-p[i-1][j-1]+p[i][j-1]+p[i-1][j];
        }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if(a[i][j]=='M')
            {
                int it=max(i-d,1);
                int jt=max(j-d,1);
                int ip=min(i+d,n);
                int jp=min(j+d,m);
                int sl=p[ip][jp]-p[it-1][jp]-p[ip][jt-1]+p[it-1][jt-1];
                if (sl>=k) kq++;
            }
        }
    cout<<kq;
    return 0;
}
