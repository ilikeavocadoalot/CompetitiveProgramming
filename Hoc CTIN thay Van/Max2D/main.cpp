#include <bits/stdc++.h>
using namespace std;
int a[100][100],s[100][100],n,m,sum,kq;
int main()
{
    freopen("Max2D.INP","r",stdin);
    freopen("Max2D.OUT","w",stdout);
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin>>a[i][j];
            s[i][j]=a[i][j]+s[i][j-1]+(s[i-1][j]-s[i-1][j-1]);
        }
    for (int j1=0; j1<n; j1++)
        for (int j2=0; j2<n; j2++)
            for (int i1=0; i1<m; i1++)
                for (int i2=0; i2<m; i2++)
                {
                    sum= s[i2][j2]-s[i1-1][j2]-(s[i2][j1-1]-s[i1-1][j1-1]);
                    if (sum>kq) kq=sum;
                }
    cout<<kq;
    return 0;
}
