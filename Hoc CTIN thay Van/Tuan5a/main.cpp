#include <bits/stdc++.h>
using namespace std;
int c[1001],b[1001];
int n,dem;
bool comp (int a, int b)
{
    return (a>=b);
}
int main()
{
    freopen("DEMTG.INP","r",stdin);
    freopen("DEMTG.OUT","w",stdout);
    cin>>n;
    vector <int> a,v;
    for (int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
        v.push_back(t);
    }
    for (int i=0; i<n; i++)
        cin>>b[i];
    for (int i=0; i<n; i++)
        cin>>c[i];
    sort(a.begin(),a.end());
    sort(v.begin(),v.end(),greater<int>());
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            std::vector <int> ::iterator k,k1;
            k=lower_bound(a.begin(),a.end(),abs(b[i]-c[j])+1);
            if (k-a.begin()<n)
            {
                k1=upper_bound(v.begin(),v.end(),(b[i]+c[j])-1,comp);
                dem+=((n-(k1-v.begin()+1))-(k-a.begin()))+1;
            }
        }
    }
    cout<<dem;
    return 0;
}
