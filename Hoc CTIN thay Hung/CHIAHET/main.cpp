#include <bits/stdc++.h>
using namespace std;
int const MAX = 10005;
bool dp[MAX][105];
int a[MAX];
int main()
{
    freopen("CHIAHET.INP","r",stdin);
    freopen("CHIAHET.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        memset (dp,false,sizeof(dp));
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
            a[i]=a[i]>0?(a[i]%k) : -(a[i]%k);
        }
        dp[0][a[0]] = true;
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<=k; j++)
            {
                if (dp[i-1][j])
                {
                    dp[i][(j+a[i]) % k ] = true;
                    dp[i][(k+j-a[i])%k]=true;
                }
            }
        }
        printf("%s\n", dp[n-1][0]? "Yes" : "No");
    }
    return 0;
}
