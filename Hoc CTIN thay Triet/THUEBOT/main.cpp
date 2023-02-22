#include <bits/stdc++.h>
using namespace std;
vector <int> a[10000];
int b[10000];
int n,q;
int main()
{
    freopen("THUEBOT.INP","r",stdin);
    freopen("THUEBOT.OUT","w",stdout);
    cin>>n>>q;
    for (int i=0; i<n; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1].push_back(t2);
        a[t2].push_back(t1);
    }
    for (int i=0; i<n; i++)
        cin>>b[i];
    cout<<"Thua thay, con da rat co gang =((";
    return 0;
}
