#include <iostream>
#include <queue>
using namespace std;
int main()
{
    freopen("DCLT.INP","r",stdin);
    freopen("DCLT.OUT","w",stdout);
    queue <int> qu;
    long long int n,m,t,sum=0;
    int dem=0;
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        cin>>t;
        qu.push(t);
        sum+=t;
        if (sum==m)
        {
            dem++;
            sum-=qu.front();
            qu.pop();
        }
        else if (sum>m)
        {
            sum-=qu.front();
            qu.pop();
            if (sum==m)
            {
                dem++;
                sum-=qu.front();
                qu.pop();
            }
        }
    }
    cout<<dem;
    return 0;
}
