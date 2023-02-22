#include <bits/stdc++.h>
using namespace std;
string s;
char b[100][100],a[100][100];
int x[5]={0,0,-1,0,1},kq;
int y[5]={0,-1,0,1,0};
void dp( int cnt)
{
    for (int i=2;i<=10;i++)
        for (int j=1;j<=10;j++)
            if (b[i-1][j]=='O')
            {
                for (int k=0;k<5;k++)
                    if (b[i+x[k]][j+y[k]]=='#') b[i+x[k]][j+y[k]]='O';
                    else if (b[i+x[k]][j+y[k]]=='O') b[i+x[k]][j+y[k]]='#';
                cnt++;
            }
    bool kt=true;
    for (int j=1;j<=10;j++)
        if (b[10][j]=='O')
        {
            kt=false;
            break;
        }
    if (kt) kq=min(kq,cnt);
}
void dq(int u,int cnt)
{
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
            b[i][j]=a[i][j];
    dp(cnt);
    for (int i=u+1;i<=10;i++)
    {
        for (int u=0;u<5;u++)
            if (a[1+x[u]][i+y[u]]=='#') a[1+x[u]][i+y[u]]='O';
            else if (a[1+x[u]][i+y[u]]=='O') a[1+x[u]][i+y[u]]='#';
        dq(i,cnt+1);
        for (int u=0;u<5;u++)
            if (a[1+x[u]][i+y[u]]=='#') a[1+x[u]][i+y[u]]='O';
            else if (a[1+x[u]][i+y[u]]=='O') a[1+x[u]][i+y[u]]='#';
    }
}
int main()
{
    freopen("TATDIEN.INP","r",stdin);
    freopen("TATDIEN.OUT","w",stdout);
    while (cin>>s)
    {
        if (s=="end") break;
        for (int i=1;i<=10;i++)
            for (int j=1;j<=10;j++)
                cin>>a[i][j];
        cout<<s;
        kq=9999999;
        dq(0,0);
        if (kq!=9999999) cout<<" "<<kq<<"\n";
        else cout<<" -1"<<"\n";
    }
    return 0;
}
