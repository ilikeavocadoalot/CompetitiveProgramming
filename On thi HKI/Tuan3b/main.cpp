//MAX HEAP
#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    freopen("Kmax.INP","r",stdin);
    freopen("Kmax.OUT","w",stdout);
    cin>>n>>k;
    priority_queue <int> pq;
    for (int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        pq.push(t);
    }
    while (k--)
    {
        cout<<pq.top()<<"\n";
        pq.pop();
    }
    return 0;
}
