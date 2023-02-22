#include <iostream>
#include <string>
#include <math.h>
#include <stack>
using namespace std;
int main()
{
    freopen ("Doanso.inp","r",stdin);
    freopen ("Doanso.out","w",stdout);
    stack <string> dau;
    stack <int> so;
    int val,kq;
    string t;
    while (cin>>t)
    {
        if ((t=="+") || (t=="-") || (t=="*")) dau.push(t);
        else if (t=="=") continue;
        else
        {
            string::size_type sz;
            val = stoi(t,&sz);
            so.push(val);
        }
    }
    kq=so.top();
    so.pop();
    while (!dau.empty())
    {
        if (dau.top()=="+") kq=kq-so.top();
        else if (dau.top()=="-") kq=kq+so.top();
        else kq=kq/so.top();
        dau.pop();
        so.pop();
    }
    cout<<kq;
    return 0;
}
