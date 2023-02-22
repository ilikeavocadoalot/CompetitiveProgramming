#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
int b[1001][1001];
int n,m,ma=0,dem=0,t1,t2;
int x[4]={-1,0,1,0};
int y[4]={0,-1,0,1};
void loangcaigimaloang (int h,int c)
{
    dem++;
    if (dem>ma) ma=dem;
    b[h][c]=1;
    for (int index=0; index < 4; index++)
    {
        h=x[index]+h;
        c=y[index]+c;
        if ((h<=m) && (h>0) && (c<=n) && (c>0) && a[h][c]=='*')
            if (a[h][c]=='*' && b[h][c]==0) loangcaigimaloang(h,c);
        h=h-x[index];
        c=c-y[index];
    }
}
int main()
{
    freopen ("FARM.INP","r",stdin);
    freopen ("FARM.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            b[i][j]=0;
        }
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            if ((b[i][j]==0) && (a[i][j]=='*'))
                loangcaigimaloang (i,j);
            dem=0;
        }
    cout<<ma<<endl;
    return 0;
}
