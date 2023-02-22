#include <bits/stdc++.h>
using namespace std;
long long int n,a,b,p,r,k,d[10000],c[10000];
int x[2];
queue <long long int> q;
int thuxemkipkhum (long long int u)
{
    q.push(u);
    d[u]=0;
    c[u]=1;
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        if (v==r) return d[v];
        x[0]=(v+a)%p;
        x[1]=(v+b)%p;
        for (int i=0; i<2; i++)
        {
            int t=x[i];
            if (t>=0 && t<=100000 && c[t]==0)
            {
                q.push(t);
                c[t]=1;
                d[t]=d[v]+1;
            }
        }
    }
	return -1;
}
int main()
{
    freopen("SODU.INP","r",stdin);
    freopen("SODU.OUT","w",stdout);
    cin>>n>>p>>a>>b>>r;
    cout<<thuxemkipkhum(n);
    return 0;
}
