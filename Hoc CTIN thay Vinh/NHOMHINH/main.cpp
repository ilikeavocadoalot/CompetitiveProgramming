#include <bits/stdc++.h>
using namespace std;
long long int n,m;
char a[10000][10000];
int d[10000][10000],dem=0;
int lailaloang (int h,int c)
{
    d[h][c]=1;
    if (a[h][c]== 'A')
    {
        if ((d[h-1][c]==0) && (a[h-1][c]=='C')) lailaloang(h-1,c);
        if ((d[h][c-1]==0) && (a[h][c-1]=='B')) lailaloang(h,c-1);
    }
    if (a[h][c]== 'B')
    {
        if ((d[h][c+1]==0) && (a[h][c+1]=='A')) lailaloang(h,c+1);
        if ((d[h-1][c]==0) && (a[h-1][c]=='D')) lailaloang(h-1,c);
    }
    if (a[h][c]== 'C')
    {
        if ((d[h][c-1]==0) && (a[h][c-1]=='D')) lailaloang(h,c-1);
        if ((d[h+1][c]==0) && (a[h+1][c]=='A')) lailaloang(h+1,c);
    }
    if (a[h][c]== 'D')
    {
        if ((d[h+1][c]==0) && (a[h+1][c]=='B')) lailaloang(h+1,c);
        if ((d[h][c+1]==0) && (a[h][c+1]=='C')) lailaloang(h,c+1);
    }
}
int main()
{
    freopen("NHOMHINH.INP","r",stdin);
    freopen("NHOMHINH.OUT","w",stdout);
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin>>a[i][j];
            d[i][j]=0;
        }
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            if (d[i][j]==0)
            {
                lailaloang(i,j);
                dem++;
            }
        }
    cout<<dem<<endl;
    return 0;
}
