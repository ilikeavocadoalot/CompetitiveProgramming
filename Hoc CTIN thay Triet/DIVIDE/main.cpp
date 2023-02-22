#include <bits/stdc++.h>
using namespace std;
string s1,s2,kq;
string numtostr (int tam)
{
    string s;
    while (tam!=0)
    {
        int t = tam%10;
        char temp;
        temp= t+'0';
        s=temp+s;
        tam=tam/10;
    }
    return s;
}
int strtonum (string tmp)
{
    int kq;
    int dem=1;
    for (int i=tmp.size()-1; i>=0; i--)
    {
        int t;
        t=tmp[i]-'0';
        kq+=t*dem;
        dem=dem*10;
    }
    return kq;
}
bool compare (string s1,string s2)
{
    if (s1.size()>s2.size()) return true;
    else if (s1.size()<s2.size()) return false;
    else
    {
        for (int i=0; i<=s1.size(); i++)
            if (s1[i]>s2[i]) return true;
    }
    return false;
}
int main()
{
    freopen("DIVIDE.INP","r",stdin);
    freopen("DIVIDE.OUT","w",stdout);
    int t;
    cin>>t;
    for (int j=1; j<=t; j++)
    {
        string kq="";
        cin>>s1;
        cin>>s2;
        string s="";
        int t1,t2,t3;
        int i=0;
        while (i<=s1.size()-1)
        {
            s=s+s1[i];
            if (compare(s,s2)==true)
            {
                t1 = strtonum(s);
                t2 = strtonum(s2);
                int tam = t1/t2;
                string tmp;
                tmp = numtostr(tam);
                kq=kq+tmp;
                if (t1%t2!=0)
                {
                    t3=t1%t2;
                    s=numtostr(t3);
                }
                else
                {
                    t3=0;
                    s="";
                }
            }
            i++;
        }
        if (t3==0) cout<<kq<<"\n";
        else cout<<kq<<" "<<t3<<"\n";
    }
    return 0;
}
