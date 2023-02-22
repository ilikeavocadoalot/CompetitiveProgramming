#include <bits/stdc++.h>
using namespace std;
int x[4] ={0,-1,0,1};
int y[4]= {-1,0,1,0};
int n,len,kq;
int a[1001],cut[1001][1001];
int solve (int dodai, int vitri)
{
    if (dodai+1==vitri)
        return 0;
    if (cut[dodai][vitri]!=-1)
        return cut[dodai][vitri];
    int kq= 9999999;
    for (int i=dodai+1; i<=vitri-1; i++)
        kq=min(kq,solve(dodai,i)+solve(i,vitri)+a[vitri]-a[dodai]);
   return cut[dodai][vitri]=kq;
}
int main()
{
    freopen("XEGO.INP","r",stdin);
    freopen("XEGO.OUT","w",stdout);
    while(1)
    {
        cin>>len;
        if (len==0)
            return 0;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        a[0]=0;
        a[n+1]=len;
        memset (cut,-1,sizeof(cut));
        cout<<solve(0,n+1)<<"\n";
    }
}
