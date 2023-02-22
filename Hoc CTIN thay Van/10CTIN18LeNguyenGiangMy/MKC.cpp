#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ii;
ii ma[200005];
int a[200005],save[100005],dem=-1,n,m,nho,nn,ans;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("MKC.inp","r",stdin);
    freopen("MKC.OUT","w",stdout);
    cin>>n>>m>>nn;
    a[1]=nn;
    nho=1;
    save[1]=1;
    for (int i=2;i<=n;i++)
    {
        cin>>a[i];
        save[i]=i;
        if (nn>a[i])
        {
            nn=min(nn,a[i]);
            nho=i;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (i!=nho)
        {
            dem++; ma[dem].first=a[i]+nn;
            ma[dem].second.first=i;
            ma[dem].second.second=nho;
        }
    }
    for (int i=dem+1;i<m+dem+1;i++)
        cin>>ma[i].second.first>>ma[i].second.second>>ma[i].first;
    sort(ma,ma+m+dem+1);
    for (int i=0;i<m+dem+1;i++)
    {
        if (save[ma[i].second.first]!=save[ma[i].second.second])
        {
            ans+=ma[i].first;
            if (save[ma[i].second.first]>save[ma[i].second.second]) nho=save[ma[i].second.first];
            else nho=save[ma[i].second.second];
            save[ma[i].second.first]=save[ma[i].second.second]=min(save[ma[i].second.first],save[ma[i].second.second]);
            for (int j=0;j<i;j++)
                if (save[ma[j].second.first]==nho || save[ma[j].second.second]==nho )
                    save[ma[j].second.first]=save[ma[j].second.second]=save[ma[i].second.first];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
