#include <bits/stdc++.h>
using namespace std;
int a[10000][10000],tam1,tam2,n,m;
int x[8]={-1,0,1,0,-1,1,1,-1};
int y[8]={0,-1,0,1,-1,1,-1,1};
queue <int> h,c;
void muoimotgioemconcode (int t1, int t2)
{
    for (int i=0; i<8; i++)
    {
        if (t1+x[i]!=tam1 || t2+y[i]!=tam2)
            if (a[t1+x[i]][t2+y[i]]==0 && t1+x[i]>=1 && t1+x[i]<=m && t2+y[i]<=n && t2+y[i]>=1)
            {
                a[t1+x[i]][t2+y[i]]=a[t1][t2]+1;
                h.push(t1+x[i]);
                c.push(t2+y[i]);
            }
    }
}
int main()
{
    freopen ("CMATRIX.INP","r",stdin);
    freopen ("CMATRIX.OUT","w",stdout);
    cin>>m>>n>>tam1>>tam2;
    tam1++;
    tam2++;
    a[tam1][tam2]=0;
    h.push(tam1);
    c.push(tam2);
    while (!h.empty())
    {
        muoimotgioemconcode (h.front(),c.front());
        h.pop();
        c.pop();
    }
    a[tam1][tam2]=0;
    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
