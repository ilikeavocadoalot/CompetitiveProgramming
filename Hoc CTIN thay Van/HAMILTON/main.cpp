#include <bits/stdc++.h>
using namespace std;
bool a[20][20];
int x[20];
bool b[20];
int n,m,start;
void PrintResult()
{
    for (int k=1;k<=n;k++)
        cout<<x[k]<<" ";
    cout<<x[1]<< endl;
    return;
}
void ReadData()
{
    freopen("Hamilton.INP","r",stdin);
    freopen("Hamilton.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=false;
    int u,v;
    for(int i=0; i<=m; i++)
    {
        cin>>u>>v;
        a[u][v]=a[v][u]=true;
    }
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
    Try(2) ;
    return 0;
}
