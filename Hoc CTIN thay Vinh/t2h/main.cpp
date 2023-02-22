#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack <string> dm;
void dq (string s)
{
    string tam="";
    int dem1=0,dem2=0;
    if (s[3]=='(')
    {
        tam= s.substr(0,3);
        dm.push(tam);
        if ((tam=="max") || (tam=="min"))
        {
            for (int i=4; i<s.size(); i++)
            {
                if (s[i]=='(') dem1++;
                else if (s[i]==')') dem2++;
                if ((s[i]==',') && (dem1==dem2))
                {
                    string temp="";
                    temp= s.substr(i+1,s.size()-i-2);
                    dq(temp);
                    temp= s.substr(4,i-4);
                    dq(temp);
                }
            }
        }
        else
        {
            string temp="";
            temp= s.substr(4,s.size()-5);
            dq(temp);
        }
    }
    else dm.push(s);
}
int main()
{
    freopen("t2h.inp","r",stdin);
    freopen("t2h.out","w",stdout);
    string s;
    getline(cin,s);
    dq(s);
    while(!dm.empty())
    {
        cout<<dm.top()<<" ";
        dm.pop();
    }
    return 0;
}
