#include <bits/stdc++.h>
#include <stdio.h>
#include <stack>
using namespace std;
stack <char> s;
int main()
{
    freopen("BTND.inp","r",stdin);
    freopen("BTND.out","w",stdout);
    int t;
    cin>>t;
    for (int tt=0; tt<=t; tt++)
    {
        int i;
        string tam,a;
        getline(cin,tam);
        for (i=0; i<=tam.size(); i++)
            if (tam[i]=='(' || tam[i]==')')
                a=a+tam[i];
        for (i=0; i<a.size(); i++)
        {
            if (a[i]=='(') s.push(a[i]);
            else if (!s.empty())
            {
                if ((a[i])==')')
                {
                    if (s.top()!='(') break;
                    else if (!s.empty()) s.pop();
                }
            }
            else if (s.empty()) break;
        }
        if (tt==0) continue;
        if (i==a.size() && (s.empty()))cout<<"1"<<endl;
        else cout<<"0"<<endl;
        while (!s.empty()) s.pop();
    }
    return 0;
}
