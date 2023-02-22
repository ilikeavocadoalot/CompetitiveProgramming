//MAX HEAP
#include <bits/stdc++.h>
using namespace std;
int n,k;
typedef pair <int,int> ii;
int main()
{
    freopen("TopK.INP","r",stdin);
    freopen("TopK.OUT","w",stdout);
    cin>>n>>k;
    priority_queue <ii> pq;
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        pq.push(ii(t,i*(-1)));
    }
    while (k--)
    {
        cout<<(pq.top().second*-1)<<" "<<pq.top().first<<"\n";
        pq.pop();
    }
    return 0;
}
