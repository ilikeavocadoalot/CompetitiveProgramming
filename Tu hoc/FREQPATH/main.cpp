#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define up(i,a,n) for (int i=a;i<=n;i++)
#define douwn(i,a,n) for (int i=a;i>=n;i--)
#define fi freopen("FREQPATH.INP","r",stdin)
#define fo freopen("FREQPATH.OUT","w",stdout)
#define pb push_back
#define fst first
#define sec second
#define all(x) x.begin(),x.end()
typedef pair<int,int> qii;
typedef long long ll;
const int inf=1e9;
const int maxn=1e5+1;
int id[]={1,-1,0,0,1,-1,1,-1};
int jd[]={0,0,1,-1,1,-1,-1,1};
int n,m,u,v,k,t,dem;
int d[maxn],low[maxn],num[maxn];
vector<int> a[maxn];
bool vst[maxn];
void taczang(int u,int p){
    num[u]=low[u]=++dem;
    for(int x:a[u]){
        if(x==p) continue;
        if(num[x]){
            low[u]=min(num[x],low[u]);
        }
        else{
            taczang(x,u);
            low[u]=min(low[u],low[x]);
        }
    }
}
void dfs(){
    memset(vst,true,sizeof(vst));
    queue<int> q;
    q.push(n);
    vst[n]=false;
    d[n]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int x:a[u]){
            if(vst[x]){
                d[x]=d[u];
                if(low[x]>=num[x]) d[x]++;
                q.push(x);
                vst[x]=false;
            }
        }
    }
}
int main(){
    fi;fo;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    up(i,1,m){
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    taczang(n,0);
    dfs();
    cin>>t;
    up(i,1,t){
        cin>>u;
        cout<<d[u]<<'\n';
    }
}
