#include<bits/stdc++.h>
typedef long long ll;
#define int long long
#define oo 1e9
#define MAX 200001
#define pb push_back
#define mp make_pair
#define p push
#define sz(x) ll (x.size())
#define le(s) ll (s.length())
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define forw(i,l,r) for(long i=l; i<=r; i++)
#define forb(i,r,l) for(long i=r; i>=l; i--)
#define pr pair<ll,ll>
#define prr pair<ll,pr>
#define rpr pair<pr,ll>
#define fi first
#define se second
#define fo "GALLERY"
#define fr freopen(fo".INP","r",stdin)
#define fw freopen(fo".OUT","w",stdout)
#define fl {fr; fw;}
#define mulsolv(n) { forw(i,1,n) solve() ;}
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL)
#define debug(x) cout << #x << " = " << x << '\n'
#define debugm(x,n) { forw(i,1,n) cout << ' ' ; debug(x); }
#define debugv(v) { cout << " SIZE: " << sz(v) << '\n'; forw(i,0,sz(v)-1) cout << i << " = " << v[i] << '\n'; cout << '\n';}
#define debugp(a) { cout << #a << " = " << a.fi << " , " << a.se << '\n'; }
#define debugvp(v) { cout << " SIZE: " << sz(v) << '\n'; forw(i,0,sz(v)-1) cout << i << " = " << v[i].fi << " , " << v[i].se << '\n'; cout << '\n';}
int mod = 1e9 + 7;
struct intM
{
    int val ;
    void operator = (int b) {val = b % mod;}
    int pow(int a , int b , int mod)
    {
        if ( b == 1 ) return a ;
        if (b % 2 == 0)
        {
            int tam = pow(a , b / 2 , mod);
            return (tam * tam) % mod ;
        } else return (a * pow( a , b- 1 , mod)) % mod;
    }
    int operator + (intM b) {return (val + b.val)% mod;}
    int operator - (intM b) {return (val - b.val + mod) % mod;}
    int operator * (intM b) {return (val * b.val) % mod;}
    int operator / (intM b) {return ((val * pow(b.val , mod-2, mod))) % mod;}

    int operator + (int b) {return (val + b) % mod;}
    int operator - (int b) {return (val - b + mod) % mod;}
    int operator * (int b) {return (val * b) % mod;}
    int operator / (int b) {return ((val * pow(b , mod - 2 , mod))) % mod ;}
};
using namespace std;
int n , m ;
int f[MAX] ;
struct Node
{
    int l , r , c;
    void insert(int _l , int _r , int _c)
    {
        l = _l , r = _r , c = _c;
    }
    bool operator < (const Node b) const{
        return l < b.l;
    }
    Node(int _u = 0, int _v = 0, int _c = 0)
    {
        l = _u , r = _v , c = _c;
    }
};
Node a[MAX];
void sub1()
{
    forw(i,0,n) f[i] =oo;
    f[0] = 0 ;
    forw(i,1,m)
    {
        int tam = f[a[i].l ] ;
        forw(j,a[i].l, a[i].r)
            f[j] = min(f[j] , tam + a[i].c) ;
    }
    cout << f[n] << '\n' ;
}
struct op
{
    bool operator () (Node a , Node b)
    {
        return a.c > b.c;
    }
};
priority_queue < Node , vector < Node > , op > stk;
void sub2()
{
    f[0 ] = 0 ;
    int htai =1 ;
    f[n] = oo ;
    forw(i,1,m)
    {
        while(htai <= a[i].l)
        {
            while(stk.top().r < htai) stk.pop();
            f[htai] = stk.top().c;
            htai ++ ;
        }
        if(stk.empty() || stk.top().c > a[i].c + f[htai -1]  ){
            stk.push(Node(a[i].l , a[i].r,f[htai -1] + a[i].c));
        } else stk.push(Node(a[i].l , a[i].r,f[htai -1] + a[i].c));
    }
    int tam = oo;
    while (!stk.empty())
    {
        if(stk.top().r >= n)
        {
            tam=  stk.top().c;
            break ;
        }
        stk.pop();
    }
    cout << min(f[n] , tam)  << '\n' ;
}
void solve(){
    cin >> n >> m ;
    forw(i,1,m)
    {
        int t1,t2,t3;
        cin >> t1 >> t2 >> t3 ;
        a[i].insert(t1,t2,t3) ;
    }
    sort ( a  + 1 , a +m + 1);
     sub2();
}
signed main()
{
    fl;
    solve();
}
