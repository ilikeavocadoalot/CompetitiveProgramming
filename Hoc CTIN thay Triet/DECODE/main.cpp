#include <bits/stdc++.h>
using namespace std;
int d[1000000],n,k,sx;
vector <int> a[1000000];
int b[1000000],c[1000000];
bool chuanbidinguna(int s)
{
    for (int i=1;i<=n;i++) d[i]=0;
    queue <int> q;
    q.push(s);
    d[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i];
            if (d[v]==0)
            {
                q.push(v);
                d[v]=1;
                if (v==sx) return false;
            }
        }
    }
    return true;
}
int main()
{
    freopen("DECODE.INP","r",stdin);
    freopen("DECODE.OUT","w",stdout);
    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++)
    {
        bool kt=true;
        int tam=0;
        int n,k;
        cin>>n>>k;
        for (int i=0; i<k; i++) a[i].clear();
        for (int j=0; j<k; j++)
        {
            int t1,t2;
            string opr;
            cin>>t1>>opr>>t2;
            if (opr=="=")
            {
                a[t1].push_back(t2);
                a[t2].push_back(t1);
            }
            else
            {
                tam++;
                b[tam]=t1;
                c[tam]=t2;
            }
        }
        for (int i=1; i<=tam; i++)
        {
            for (int i=1;i<=n;i++) d[i]=0;
            sx=c[i];
            if (chuanbidinguna(b[i])==false)
            {
                cout<<"NO"<<"\n";
                kt=false;
            }
            b[i]=0;
            c[i]=0;
        }
        if (kt==true) cout<<"YES"<<"\n";
    }
    return 0;
}
