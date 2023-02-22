#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("KHUYENMAI.INP","r",stdin);
    freopen("KHUYENMAI.OUT","w",stdout);
    long long int n,t,i,tong=0;
    cin>>n;
    priority_queue <int> pq;
    for (i=0; i<n; i++)
    {
        cin>>t;
        pq.push(t);
    }
    i=1;
    while (!pq.empty())
    {
        if (i%3!=0) tong+=pq.top();
        i++;
        pq.pop();
    }
    cout<<tong;
}

