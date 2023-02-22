#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000][10000],d[10000][10000],dem,ma=0;
int x[8]={-1,0,1,0,1,1,-1,-1};
int y[8]={0,-1,0,1,1,-1,1,-1};
int lamontoimuonnghi (int h, int c)
{
    d[h][c]=1;
    if (a[h][c]>ma) ma= a[h][c];
    for (int index=0; index < 8; index++)
    {
        h=x[index]+h;
        c=y[index]+c;
        if ((h<n) && (h>=0) && (c<m) && (c>=0) && a[h][c]!=0)
            if ((a[h][c]!=0) && (d[h][c]!=1))
            {
                lamontoimuonnghi(h,c);
            }
        h=h-x[index];
        c=c-y[index];
    }
}
int main()
{
    freopen("MIENSO.INP","r",stdin);
    freopen("MIENSO.OUT","w",stdout);
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin>>a[i][j];
            d[i][j]=0;
        }
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (d[i][j]==0 && a[i][j]!=0)
            {
                lamontoimuonnghi(i,j);
                dem++;
            }
    cout<<dem<<endl;
    return 0;
}
