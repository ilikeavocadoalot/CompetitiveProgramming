#include <iostream>
#include <string>
#include <math.h>
#include <stack>
using namespace std;
int a=0,b=0,val,n,t1,t2;
string s,c[1000];
stack <float> so;
/*void xuly (int &n)
{
    for (int i=1; i<n; i++)
    {
        if ((c[i]=="*") || (c[i]=="/"))
        {
            for (int j = i-1; j <=n+1; j++)
                c[j] = c[j-1];
            c[i-1] = "(";
            n++;
            for (int j = i+1; j <=n+1; j++)
                c[j] = c[j-1];
            c[i+1] = ")";
            n++;
        }
    }
    for (int i=1; i<n; i++)
    {
        if ((c[i]=="+") || (c[i]=="-"))
        {
            for (int j = i-1; j <=n+1; j++)
                c[j] = c[j-1];
            c[i-1] = "(";
            n++;
            for (int j = i+1; j <=n+1; j++)
                c[j] = c[j-1];
            c[i+1] = ")";
            n++;
        }
    }
}*/
int main ()
{
    freopen ("Caycongthuc.inp","r",stdin);
    freopen ("Caycongthuc.out","w",stdout);
    float kq;
    n=0;
    while (cin>>s)
    {
        n++;
        c[n]=s;
    }
    stack <string> ngoac, dau;
    for (int i=1; i<=n; i++)
    {
        if (c[i]=="(")
            ngoac.push(c[i]);
        else if ((c[i]=="+") || (c[i]=="-") || (c[i]=="*") || (c[i]=="/"))
            dau.push(c[i]);
        else if (c[i]==")")
        {
            t2= so.top();
            so.pop();
            t1= so.top();
            so.pop();
            if (dau.top()=="+") kq=t1+t2;
            else if (dau.top()=="-") kq=t1-t2;
            else if (dau.top()=="*") kq=t1*t2;
            else kq=t1/t2;
            so.push(kq);
            ngoac.pop();
            dau.pop();
        }
        else
        {
            string::size_type sz;
            val = stoi(c[i],&sz);
            so.push(val);
        }
    }
    t2= so.top();
    so.pop();
    if (!so.empty())
    {
        t1= so.top();
        so.pop();
        if (dau.top()=="+") kq=t1+t2;
        else if (dau.top()=="-") kq=t1-t2;
        else if (dau.top()=="*") kq=t1*t2;
        else kq=t1/t2;
    }
    cout<<kq<<"\n";
}
