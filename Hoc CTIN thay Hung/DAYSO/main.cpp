#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("DAYSO.INP","r",stdin);
    freopen("DAYSO.OUT","w",stdout);
    long long int n,t,i;
    cin>>t;
    for (int j=0;j<t;j++)
    {
        cin>>n;
        long long int kq=0,tam=1,i=0,t1=0,dong=0,gh=10;
        for (i=1;i<10;i++)
        {
            kq=kq+i;
            if (kq>=n)
            {
                kq=kq-tam*i;
                break;
            }
        }
        tam=2;
        dong=9;
        i=10;
        gh=100;
        while (kq<n)
        {
            i++;
            dong=dong+tam;
            kq=kq+dong;
            if (i==gh)
            {
                tam++;
                gh=gh*10;
            }
        }
        t1=kq-dong;
        i=0;
        tam=1;
        gh=10;
        long long int cuoi=0;
        while (t1<n)
        {
            i++;
            if (i==gh)
            {
                tam++;
                gh=gh*10;
            }
            t1+=tam;
            cuoi++;
        }
        int chuso=t1-n;
        for (i=0;i<chuso+1;i++)
        {
            tam=cuoi % 10;
            cuoi =cuoi / 10;
        }
        cout<<tam<<endl;
    }
    return 0;
}
