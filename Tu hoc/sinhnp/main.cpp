#include <bits/stdc++.h>
using namespace std;
int n,i,b[1000];
void dq (int i)
{
    for (int j=0; j<=1; j++)
    {
        b[i]=j;
        if (i==n)
        {
            for (int t=1; t<=n; t++) cout<<b[t];
            cout<<endl;
        }
        else dq(i+1);
    }
}
int main()
{
    cin>>n;
    dq(1);
    return 0;
}
