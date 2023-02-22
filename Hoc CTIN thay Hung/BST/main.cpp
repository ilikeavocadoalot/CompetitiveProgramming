#include <bits/stdc++.h>
using namespace std;
int a[251],pre[251],n,dp[251][251];
int dequy ()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n-i+1; j++)
        {
            if (i==1)
            {
                dp[j][j]=a[j];
                continue;
            }
            int tam=i+j-1;
            dp[j][tam]=INT_MAX;
            for (int index=j; index<=tam; index++)
            {
                int t=(index> j?dp[j][index-1]:0) + (index<tam ?dp[index+1][tam]:0) + pre[tam]-pre[j-1];
                dp[j][tam]=min(dp[j][tam],t);
            }
        }
    return dp[1][n];
}
int main ()
{
    //freopen ("BST.INP","r",stdin);
    //freopen ("BST.OUT","w",stdout);
    while (cin>>n)
    {
        pre[0]=0;
        for (int ii=1; ii<=n; ii++)
        {
            cin>>a[ii];
            pre[ii]=a[ii]+pre[ii-1];
        }
        cout<<dequy()-pre[n]<<"\n";
    }
}
