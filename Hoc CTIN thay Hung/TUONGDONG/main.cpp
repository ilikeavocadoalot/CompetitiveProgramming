#include <bits/stdc++.h>
using namespace std;
int t=1;
int main()
{
    freopen("TUONGDONG.INP","r",stdin);
    freopen("TUONGDONG.OUT","w",stdout);
    while (t!=0)
    {
        cin>>t;
        if (t==0) break;
        map <vector <int>,int> qua;
        int ma=0;
        for (int i=0; i<t; i++)
        {
            vector <int> v;
            for (int j=0; j<5; j++)
            {
                int tmp;
                cin>>tmp;
                v.push_back(tmp);
            }
            sort(v.begin(),v.end());
            qua[v]++;
            if (qua[v]>1 && qua[v]>ma) ma=qua[v];
        }
        if (ma==0) cout <<t<<"\n";
        else cout<<ma<<"\n";
    }
    return 0;
}
