//MAX HEAP
#include <bits/stdc++.h>
using namespace std;
int m,n,k,t=0,i=0,j=0;
int a[50000],b[50000],kq[50000];
int main()
{
    freopen("HaiDaySo.inp","r",stdin);
    freopen("HaiDaySo.out","w",stdout);
    cin>>m>>n>>k;
    priority_queue <int> pq;
    for (i=1; i<=m; i++)
        cin>>a[i];
    for (j=1; j<=n; j++)
        cin>>b[j];
    sort(a,a+m);
    sort(b,b+n);
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            t++;
            pq.push(a[i]+b[j]);
            if (t==k) break;
        }
        if (t==k) break;
    }
    for (j=j+1; j<=n; j++)
    {
        if (a[i]+b[j]<pq.top())
        {
            pq.pop();
            pq.push(a[i]+b[j]);
        }
        else break;
    }
    for (i=i+1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (a[i]+b[j]<pq.top())
            {
                pq.pop();
                pq.push(a[i]+b[j]);
            }
            else break;
        }
    }
    for (i=1; i<=k; i++)
    {
        kq[i]=pq.top();
        pq.pop();
    }
    for (i=k; i>=1; i--)
        cout<<kq[i]<<endl;
    return 0;
}
