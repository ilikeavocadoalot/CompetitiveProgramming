#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int x[20];
bool b[20];
int dem=0,kq=0;
int n,m,start;
void PrintResult()
{
    dem++;
    return;
}
bool ktra (int n)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]!=a[j][i]) return false;
    return true;
}
void ReadData()
{
    freopen("Hamilton.INP","r",stdin);
    freopen("Hamilton.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    if (ktra(n)==true) kq=1;
    else kq=2;
    return;
}
void Try (int i)
{
    for (int j=2;j<=n; j++)
        if ((b[j])&&(a[x[i-1]][j]))
        {
            x[i]=j;
            b[j]=false;
            if (i<n)
                Try(i+1);
            else if (a[x[i]][x[1]])
                PrintResult();
            b[j]=true;
        }
    return;
}
int main()
{
    ReadData();
    for (int i=1; i<=n;i++)
        b[i]=true;
    start=1;
    x[1]=start;
    b[start]=false;
    Try(2);
    if (kq==1 && dem!=0) cout<<1;
    else if (kq==1 && dem==0) cout<<2;
    else if (kq==2 && dem!=0) cout<<3;
    else if (kq==2 && dem==0) cout<<4;
    else cout<<5;
    return 0;
}
