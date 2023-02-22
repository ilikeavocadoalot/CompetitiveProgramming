#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
int n,m,s,kq1,kq2,ma;
ii a[100000],b[100000];
int bs(int x)
{
    int left = 1 ,right=m,kq=0;
    while (left<=right)
    {
        int middle = (left+right)>>1;
        if (b[middle].first<=x)
        {
           kq=middle;
           left=middle+1;
        }
        else
          right=middle -1;
    }
    return kq;
}
struct data
{
    int left,right,luu;
};
data kq;
int main()
{
    freopen("FLOWERS.INP","r",stdin);
    freopen("FLOWERS.OUT","w",stdout);
    cin>>n>>m>>s;
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        a[i].first=t;
        a[i].second=i;
    }
    for (int i=1; i<=m; i++)
    {
        int t;
        cin>>t;
        b[i].first=t;
        b[i].second=i;
    }
    kq.left=0;
    kq.right=0;
    kq.luu=0;
    sort(b+1,b+1+m);
    for (int i=1; i<=n; i++)
    {
        if (a[i].first>s) continue;
        int pos = bs(s-a[i].first);
        if (pos==0) continue;
        if (kq.luu< a[i].first+b[pos].first)
        {
            kq.luu=a[i].first+b[pos].first;
            kq.left=a[i].second;
            kq.right=b[pos].second;
        }
    }
    cout<<kq.left<<" "<<kq.right<<endl;
}
