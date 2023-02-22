#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n,t,i,tong=0;
    cin>>n;
    priority_queue <int> pq;
    for (int i=0; i<n; i++)
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
    return 0;
}
