#include <bits/stdc++.h>
#define int long long

using namespace std;
const int maxn = 25;
bool a[maxn][maxn];
int ptd[maxn] ;
bool mark[maxn];
int n,m,u,v;

void dq(int i){
    for (int j=2;j<=n;j++){
        if (mark[j] && a[ptd[i-1]][j]){
            ptd[i]=j;
            mark[j]=false;
            if (i<n) dq(i+1);
            else if (a[ptd[i]][ptd[1]]) {
                for (int k=1;k<=n;k++) cout<<ptd[k]<<" ";
                cout<<ptd[1]<<"\n";
            } mark[j]=true;
        }
    } return ;
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("hamilton.inp","r",stdin);
    freopen("hamilton.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) a[i][j]=false;
    for (int i=0;i<m;i++){
        cin>>u>>v;
        a[u][v]=a[v][u]=true;
    } memset(mark,true,sizeof(mark));
    ptd[1]=1; mark[1]=false;
    dq(2);
    return 0;
}
