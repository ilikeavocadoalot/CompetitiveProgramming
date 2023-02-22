#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, pair <int, int> > iii;
const int maxn = 1e6 + 5;
long long n,u[maxn],v[maxn];
iii a[maxn];
vector< pair<int,int> > ans;

bool cmp(iii a,iii b){
    return a.se.fi < b.se.fi;
}

bool comp(ii a,ii b){
    return abs(a.fi-a.se) < abs(b.fi-b.se);
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("greed_line.inp","r",stdin);
    freopen("greedy_line.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>u[i]>>v[i];
        a[i].fi = min(u[i],v[i]);
        a[i].se.fi = max(u[i],v[i]);
        a[i].se.se = i;
    } sort(a,a+n,cmp);
    ans.push_back({u[a[0].se.se],v[a[0].se.se]});
    int en = a[0].se.fi;
    for (int i=1;i<n;i++){
        if (en <= a[i].fi){
            ans.push_back({u[a[i].se.se],v[a[i].se.se]});
            en = a[i].se.fi;
        }
    } sort(ans.begin(),ans.end(),comp);
    for (int i=0;i<ans.size();i++) cout<<ans[i].fi<<" "<< ans[i].se<<"\n";
    return 0;
}
