#include <bits/stdc++.h>
using namespace std;
signed main()
{
    double ans = 0;
    for (double i = 1;i<=90;i++)
    {
        ans = ((i+3) + (i+4) - (i+5)) / (i - (i+1) - (i+2));
    }
    cout<<fixed<<setprecision(2)<<"Tong ="<<ans;
    return 0;
}
