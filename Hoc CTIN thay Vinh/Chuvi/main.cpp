#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int n,dem;
typedef pair <int,int> ii;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
void mn (int t1, int t2)
{
    queue <ii> q;
    q.push(ii(t1,t2));
    a[t1][t2]='O';
    while (!q.empty())
    {
        int ui = q.front().first;
        int uj = q.front().second;
        a[ui][uj]='O';
        q.pop();
        for (int index=0; index<4; index++)
        {
            int vi=ui+x[index];
            int vj=uj+y[index];
            if (vi>=0 && vj>=0 && vi<=100 && vj<=100)
            {
                if (a[vi][vj]!='X' && a[vi][vj]!='O')
                {
                    q.push(ii(vi,vj));
                    a[vi][vj]='O';
                }
                else if (a[vi][vj]=='X') dem++;
            }
        }
    }
}
int main()
{
    freopen("Chuvi.inp","r",stdin);
    freopen("Chuvi.out","w",stdout);
    cin>>n;
    for (int i=0; i<n; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1][t2]='X';
    }
    mn(0,0);
    cout<<dem;
    return 0;
}
