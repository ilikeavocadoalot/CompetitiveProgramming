#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define FORW(i,a,b) for(int i=a;i<=b;i++)
#define FORB(i,a,b) for (int i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define endl "\n"
#define db(val) "["#val" = "<<(val)<<"] "
#define CNTBIT(x) __builtin_popcountll(x)
#define ODDBIT(x) __builtin_parityll(x)
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define SUBSET(big, small) (((big)&(small))==(small))
#define FIRSTBIT(x) __builtin_ctzll((x)&(-x))
#define file "ralph"
#define sqr(x) (x)*(x)
int dX[] ={0,-1,0,1};
int dY[]= {-1,0,1,0};
const int oo=1e9;
const ll MOD=1e9+7;
const ll mod=1e9+9;
const int mxN = 1e3;
struct info{
    int x,y;
}a[mxN],b[mxN];
int c[mxN][mxN],f[mxN][mxN],par[mxN],s,t,N,n,m;
int dist(info a, info b ){
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
bool findPath(){
//    cout<<"1"<<endl;
    for (int i = 1 ;i<=N;i++)
        par[i]=0;
    queue<int> q;
    q.push(s);
    par[s]=N+1;
    while(q.size()){
        int u = q.front();
//        cout<<u<<endl;
        q.pop();
        for (int v = 1 ;v<=N;v++)
            if (!par[v]&&c[u][v]-f[u][v]>0){
                par[v]=u;
                if (v==t) return 1;
                q.push(v);
        }
    }
    return 0;
}
void incFlow(){
    int delta=oo;
    for (int v=t; v!=s;v=par[v]){
        int u = par[v];
        delta=min(delta,c[u][v]-f[u][v]);
    }
    for (int v= t; v!=s;v=par[v]){
        int u = par[v];
        f[u][v]+=delta;
        f[v][u]-=delta;
    }

}
void solve(){
    cin>>n>>m;
    memset(c,0,sizeof c);
    memset(f,0,sizeof f);
    for (int i = 1 ;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    for (int i = 1 ;i<=m;i++){
        cin>>b[i].x>>b[i].y;
    }
    s=n+m+1,t=n+m+2,N=n+m+2;
    for (int i = 1 ;i<n;i++)
        c[s][i]=1;
    for (int i = 1 ;i<n;i++)
        for (int j = 1 ;j<=m;j++)
          if (dist(a[i],b[j])+dist(a[i+1],b[j])<2*dist(a[i],a[i+1]))
            c[i][n+j]=1;
    for (int i = 1 ;i<=m;i++)
        c[n+i][t]=1;
    while(findPath())
        incFlow();
    int res=0;
    for (int i = 1 ;i<n;i++)
        if (f[s][i]>0)
         res+=f[s][i];
    cout<<res+n;


}
signed main(){
        fast;
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
        int t;
        cin>>t;
        while(t--)
            solve();
}

