#include <bits/stdc++.h>
using namespace std;
int t,n,a[9999],b[9999],c[9999],datham[9999],dau,cuoi;
vector <int> v[9999];
int nuademgoi ()
{
    memset(datham,0,sizeof(datham));
    queue <int> qu;
    qu.push(0);
    datham[0]=1;
    while (!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        for (int i=0; i<v[u].size(); i++)
            if (!datham[v[u][i]])
            {
                datham[v[u][i]]=datham[u]+1;
                qu.push(v[u][i]);
                if (v[u][i]==n+1)
                    return datham[n+1]-2;
            }
    }
    return -1;
}
int main()
{
    freopen("SLING.INP","r",stdin);
    freopen("SLING.OUT","w",stdout);
    cin>>t;
    for (int ii=0; ii<t; ii++)
    {
        cin>>n;
        for(int j=0; j <= 9999; j++)
            v[j].clear();
        for (int j=1; j<=n; j++)
            cin>>a[j]>>b[j]>>c[j];
        cin>>dau>>cuoi;
        for (int i=1; i<=n; i++)
        {
            for (int j=i+1; j<=n; j++)
            {
                double x = a[i]-a[j];
                double y = b[i]-b[j];
                if(sqrt(x*x+y*y) <= c[i]+c[j])
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
            if (b[i]-c[i]<=cuoi) v[0].push_back(i);
            if (b[i]+c[i]>=dau) v[i].push_back(n+1);
        }
        cout << nuademgoi()<<"\n";
    }
    return 0;
}
