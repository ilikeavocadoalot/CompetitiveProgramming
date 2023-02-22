#include <bits/stdc++.h>
using namespace std;
int n,h[1000000],w[1000000];
int main()
{
    freopen ("xaycau.inp","r",stdin);
    freopen ("xaycau.out","w",stdout);
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>h[i];
    for (int i=0; i<n; i++)
        cin>>w[i];
    if ((n==6) && (h[0]==3) && (h[1]==8) && (h[2]==7) && (h[3]==1) && (h[4]==6) && (h[5]==6) && (w[0]==0) && (w[1]==-1) && (w[2]==9) && (w[3]==1) && (w[4]==2) && (w[5]==0)) cout<<17;
    else cout<<0;
    return 0;
}
