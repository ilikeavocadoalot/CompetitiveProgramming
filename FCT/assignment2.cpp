#include <bits/stdc++.h>
#include <queue>
using namespace std;
int main ()
{
    int n;
    priority_queue <long long int> pq;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        long long int t;
        cin>>t;
        pq.push(t);
    }
    long long int t1=pq.top();
    pq.pop();
    long long int t2=pq.top();
    long long int ans;
    ans=t1*t2;
    cout<<ans;
    return 0;
}
