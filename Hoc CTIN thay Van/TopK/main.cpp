#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    freopen("TOPK.INP","r",stdin);
    freopen("TOPK.OUT","w",stdout);
    long n,k,t,a[200000],b[200000];
    priority_queue <pair<int,int>> pq;
    cin>>n>>k;
    for (int i=0; i<n; i++)
    {
        cin>>t;
        pq.push(make_pair(t,-i));
    }
    for (int i=0; i<k; i++)
    {
        cout<<abs(pq.top().second)+1<<" "<<pq.top().first<<endl;
        pq.pop();
    }
    return 0;
}
