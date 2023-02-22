#include <bits/stdc++.h>
using namespace std;
int n,a[100000],lid[100000],l[100000],trace[100000],pos,cuoi,lis;
int main()
{
    freopen("LIS.INP","r",stdin);
    freopen("LIS.OUT","w",stdout);
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    lis=0;
    pos=0;
    cuoi=0;
    for (int i=0; i<n; i++)
    {
        pos=lower_bound(l,l+lis,a[i])-l;
        l[pos]=a[i];
        lid[pos]=i;
        trace[i]=pos ? lid[pos-1]:-1;
        if (pos+1>lis)
        {
            lis=pos+1;
            cuoi=i;
        }
    }
    stack <int> s;
    int x= cuoi;
    for (; x>=0; x=trace[x])
        s.push(x+1);
    cout <<lis<<"\n";
    for (; !s.empty(); s.pop())
        cout << s.top()<< " ";
    return 0;
}
