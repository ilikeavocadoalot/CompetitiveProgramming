#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DEMBUOC.INP","r",stdin);
    freopen("DEMBUOC.OUT","w",stdout);
    int t;
    cin>>t;
    for (int index=1; index<=t; index++)
    {
        int x,y;
        cin>>x>>y;
        if (x==y) cout<<0;
        else if (y-x<=3) cout<<y-x;
        else
        {
            int tam =y-x-2;
            if (tam==3) cout<<4;
            else if (tam<=2) cout<<3;
            else
            {
                int tmp = tam/2;
                int i=2;
                int cnt=0;
                int dem=0;
                while (dem+i<=tmp)
                {
                    dem+=i;
                    cnt++;
                    i++;
                }
                i--;
                if (tam-(dem*2)==0) cout<<cnt*2+2;
                else
                {
                    int temp = tam - (dem*2);
                    if ((temp-i)<=1) cout<<cnt*2+3;
                    else cout<<cnt*2+4;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
