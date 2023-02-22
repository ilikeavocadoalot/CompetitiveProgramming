#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int main()
{
    int n,k,a[200000];
    priority_queue<int> pq;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        pq.push(a[i]);
    }
    while (k!=0)
    {
        cout<<pq.top()<<endl;
        pq.pop();
        k--;
    }
    return 0;
}
