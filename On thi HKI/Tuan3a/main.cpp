//MIN HEAP
#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    freopen("Kmin.INP","r",stdin);
    freopen("Kmin.OUT","w",stdout);
    priority_queue <int, vector <int>, greater <int>> pq;
    cin>>n>>k;
    for (int i=1; i<n; i++)
    {
        int t;
        cin>>t;
        pq.push(t);
    }
    while (k--)
    {
        cout <<pq.top()<<"\n";
        pq.pop();
    }
    return 0;
}
