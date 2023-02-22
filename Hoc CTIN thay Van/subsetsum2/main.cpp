#include <bits/stdc++.h>
using namespace std;
long long int n,t,i,j,s,way[10000][10000];
int main()
{
    freopen("Subset.inp","r",stdin);
    freopen("Subset.out","w",stdout);
    cin>>n;
    t=(n*(n+1))/2;
    if (t%2!=0) cout<<0;
    else
    {
        s=t/2;
        for (int j=1; j<=s; j++) way[0][j]=0;
        for (int i=0; i<=n; i++) way[i][0]=1;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=i*(i+1)/2; j++)
                if (j>=i) way[i][j]=way[i-1][j]+way[i-1][j-i];
                else way[i][j]=way[i-1][j];
        cout<<way[n][s]/2;
    }
    return 0;
}
