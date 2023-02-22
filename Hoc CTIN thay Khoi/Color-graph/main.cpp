#include <bits/stdc++.h>
using namespace std;
long long n,m,u,v;
vector<long long> a[700];
long long ans[700];
bool mark[700];
void gm(){
	memset(ans,-1,sizeof(ans)); ans[0]=0;
	memset(mark,false,sizeof(mark));
	for (int u=1;u<n;u++){
        for (int i=0;i<a[u].size();i++){
            int tam=a[u][i];
            if (ans[tam]!=-1){
                mark[ans[tam]]=true;
            }
        } for (int i=0;i<m;i++){
            if (!mark[i]){
                ans[u]=i;
                break;
            }
		} for (int i=0;i<a[u].size();i++)
            if (ans[a[u][i]]!=-1)
                mark[ans[a[u][i]]]=false;
	} for (int u=0;u<n;u++)
        if (ans[u]==-1) {
            cout<<-1;
            return ;
        }
	for (int u=0;u<n;u++)
		cout<<ans[u]+1<<" ";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("Color-Graph.inp","r",stdin);
    freopen("Color-Graph.out","w",stdout);
    cin>>n>>m;
	for (int i=0;i<m;i++){
        cin>>u>>v; u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
	} gm();
	return 0;
}
