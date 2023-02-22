#include <bits/stdc++.h>
using namespace std;
int n,t,a[50005];
typedef pair <int,int> ii;
ii tree[200005];
void buildTree (int no, int l, int r)
{
    if (l==r)
    {
        tree[no] = {a[l],a[l]};
        return;
    }
    int m =(l+r)/2;
    buildTree(no*2,l,m);
    buildTree(no*2+1,m+1,r);
    tree[no]={max(tree[no*2].first,tree[no*2+1].first),min(tree[no*2].second,tree[no*2+1].second)};
}
ii getval (int no, int l, int r, int u, int v)
{
    if (u>r || v<l)
        return {INT_MIN,INT_MAX};
    if (l>=u && r<=v)
        return tree[no];
    int m= (l+r)/2;
    return {max(getval(no*2,l,m,u,v).first,getval(no*2+1,m+1,r,u,v).first),min(getval(no*2,l,m,u,v).second,getval(no*2+1,m+1,r,u,v).second)};
}
int main()
{
    freopen("STOCKS.INP","r",stdin);
    freopen("STOCKS.OUT","w",stdout);
    cin>>n>>t;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    buildTree(1,1,n);
    for (int index=1; index<=t; index++)
    {
        int l,r;
        ii kq;
        cin>>l>>r;
        kq=getval(1,1,n,l,r);
        cout<<kq.first-kq.second<<"\n";
    }
    return 0;
}
