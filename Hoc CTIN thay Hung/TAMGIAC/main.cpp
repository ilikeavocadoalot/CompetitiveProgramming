#include <bits/stdc++.h>
using namespace std;
const long long maximumn = 1e4;
const long long maximumh = 1e6+5;
string ar[maximumn];
long long n, height[maximumh];
signed main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("TAMGIAC.INP","r",stdin);
    freopen("TAMGIAC.OUT","w",stdout);
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>ar[i];
    long long kq=0;
    for (int i=1; i<n; i++)
    {
        for (int j=0; j<(int)ar[i].size(); j++)
        {
            if (ar[i][j]=='-')
            {
                if (ar[i-1][j+1]=='-') height[j]= 1 + min(height[j],height[j+2]);
                else height[j]=1;
            }
            else height[j]=0;
            kq = max(kq, height[j]);
        }
    }
    memset (height,0,sizeof(height));
    for (int i=0; i<n; i++)
    {
        for (int j=1; j<(int)ar[i].size(); j++)
        {
            if (ar[i][j]=='-')
            {
                if (ar[i+1][j-1]=='-') height[j]= 1 + min(height[j],height[j+2]);
                else height[j]=1;
            }
            else height[j]=0;
            kq = max(kq, height[j]);
        }
    }
    cout<<kq*kq;
    return 0;
}
