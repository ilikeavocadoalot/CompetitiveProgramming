#include <bits/stdc++.h>
using namespace std;
typedef pair <double,int> ii;
ii st[10000];
int tt;
bool compare(ii &a,ii &b)
{
    if (a.first == b.first)
        return a.second<b.second;
    else return a.first>b.first;
}
int main()
{
    freopen("DONGGIAY.INP","r",stdin);
    freopen("DONGGIAY.OUT","w",stdout);
    cin>>tt;
    for (int j=0; j<tt; j++)
    {
        int n;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            double a,b;
            cin>>a>>b;
            st[i].first = b/a;
            st[i].second = i;
        }
        sort(st,st+n,compare);
        for (int i=0; i<n; i++)
            cout<<st[i].second+1<<" ";
        cout<<"\n";
    }
    return 0;
}
