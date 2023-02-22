#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,m,u,v;
vii lgh[100005];
int mark[200005];
void ptd(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>u>>v;
        lgh[u].push_back({v,i});
        lgh[v].push_back({u,i});
    } for (int i=1;i<=n;i++){
        if (lgh[i].size()&1){
            cout<<"IMPOSSIBLE ";
            return ;
        }
    }stack<int> st; st.push(1);
    vi path;
    while(!st.empty()){
        int v = st.top(); int kt=0;
        while(!lgh[v].empty()) {
            ii tam =  lgh[v].back();
            int u = tam.fi, i = tam.se;
            lgh[v].pop_back();
            if (!mark[i]) {
                st.push(u);
                mark[i]=1;kt=1;
                break;
            }
        } if (!kt) {
            path.push_back(v);
            st.pop();
        }
    } if (path.size()!=m+1) {
        cout<<"IMPOSSIBLE ";
        return;
    } for (auto i: path) cout<<i<<" ";
}
signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("mail.inp", "r" , stdin);
    freopen("mail.out", "w", stdout);
    ptd();
    return 0;
}
