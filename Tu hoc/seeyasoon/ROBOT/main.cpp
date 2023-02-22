#include <bits/stdc++.h>
using namespace std;
string l;
char a[100][100];
int v[100][100][4][10];
int n,m,k,dem,tam;
int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};
bool chacphaidailam (int i, int j)
{
    int c=0;
    int d=0;
    while (true)
    {
        if (a[i][j]=='E') return (true);
        if (v[i][j][c][d]==1) return (false);
        if (v[i][j][c][d]==0)
        v[i][j][c][d]=1;
        if (l[d]=='F')
        {
                if (i+x[c]>=0 && j+y[c]>=0 && i+x[c]<n && j+y[c]<m && a[i+x[c]][j+y[c]]!='#')
                {
                    i+=x[c];
                    j+=y[c];
                }
        }
        else if (l[d]=='R') c++;
        else c--;
        d++;
        if (d==k) d=0;
        if (c==-1) c=3;
        if (c==4) c=0;
    }
}
int main()
{
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin>>a[i][j];
            if (a[i][j]!='#') dem++;
        }
    cin>>l;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i][j]!='#')
            {
                memset(v,0,sizeof(v));
                if (chacphaidailam(i,j)) tam++;
            }
    if (tam==dem) cout<<"YES";
    else cout<<tam;
    return 0;
}
