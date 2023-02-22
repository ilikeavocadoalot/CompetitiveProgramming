#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
stack <char> s;
int main()
{
    freopen("Dayngoac.inp","r",stdin);
    freopen("Dayngoac.out","w",stdout);
    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++)
    {
        string a;
        cin>>a;
        int i;
        for (i=0; i<a.size(); i++)
        {
            if ((a[i]=='(') || (a[i]=='{') || (a[i]=='[')) s.push(a[i]);
            else if (!s.empty())
            {
                if ((a[i])==')')
                {
                    if (s.top()!='(') break;
                    else if (!s.empty()) s.pop();
                }
                else if ((a[i]=='}'))
                {
                    if (s.top()!='{') break;
                    else if (!s.empty()) s.pop();
                }
                else
                {
                    if (s.top()!='[') break;
                    else if (!s.empty()) s.pop();
                }
            }
        }
        if (i==a.size() && (s.empty()))cout<<1<<endl;
        else cout<<0<<endl;
        while (!s.empty()) s.pop();
    }
    return 0;
}
