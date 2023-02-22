#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef pair <int, pair<int, int> > iii;
const int maxn = 1e4 + 10;
const int inf = 1e9 + 7;
int n;
vector<int> ansdungh,anstreh;
iii a[maxn];

bool cmp(iii a,iii b){
    return a.se.fi == b.se.fi ? ( a.fi == b.fi ? a.se.se < b.se.se : a.fi < b.fi ) : a.se.fi < b.se.fi;
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("joblate.inp","r",stdin);
    freopen("joblate.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i].fi;
    for (int i=0;i<n;i++){
        cin>>a[i].se.fi;
        a[i].se.se=i+1;
    } sort(a,a+n,cmp);
    int now=0;
    for (int i=0;i<n;i++){
        if (a[i].fi + now <=a[i].se.fi){
            now += a[i].fi;
            ansdungh.push_back(a[i].se.se);
        } else anstreh.push_back(a[i].se.se);
    } cout<<anstreh.size()<<"\n";
    for (int i=0;i<ansdungh.size();i++) cout<<ansdungh[i]<<" ";
    for (int i=0;i<anstreh.size();i++) cout<<anstreh[i]<<" ";
    return 0;
}
