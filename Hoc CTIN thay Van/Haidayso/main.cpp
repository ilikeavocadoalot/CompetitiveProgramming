#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[50000],b[50000];
int i,j,t;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("HaiDaySo.INP","r",stdin);
    freopen("HaiDaySo.OUT","w",stdout);
    cin>>m>>n>>k;
    priority_queue <int> pq;
    for (int i=0; i<m; i++) cin>>a[i];
    for (int i=0; i<n; i++) cin>>b[i];
    sort(a,a+m);
    sort(b,b+n);
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            t++;
            pq.push(a[i]+b[j]);
            if (t==k) break;
        }
        if (t==k) break;
    }
    j++;
    for (int e=i; e<m; e++)
    {
        for (int w=j; w<n; w++)
        {
            if (a[e]+b[w]<pq.top())
            {
                pq.pop();
                pq.push(a[e]+b[w]);
            } else break;
        }
        j=0;
    }
    for (i=0; i<k; i++)
    {
        a[i]=pq.top();
        pq.pop();
    }
    for (i=k-1; i>=0; i--)
        cout<<a[i]<<endl;
    return 0;
}
