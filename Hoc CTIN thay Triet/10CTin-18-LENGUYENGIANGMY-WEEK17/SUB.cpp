#include <bits/stdc++.h>
using namespace std;
int n,t;
string xulytru(string a,string b)
{
    string s;
    int nho=0;
    if (b>a)
    {
        string tam;
        tam=a;
        a=b;
        b=tam;
    }
    for (int i=a.size()-1; i>=0; i--)
    {
        int t1=a[i]-'0';
        int t2=b[i]-'0';
        t=t1-(t2+nho);
        if (t>=0)
        {
            char tam;
            tam = t+'0';
            s=tam+s;
            nho=0;
        }
        else
        {
            char tam;
            t=(t1+10)-(t2+nho);
            tam= t+'0';
            s=tam+s;
            nho=1;
        }
    }
    string kq;
    int i=0;
    while (s[i]=='0')
        i++;
    for (int j=i; j<=s.size()-1; j++)
        kq=kq+s[j];
    return kq;
}
string xulycong(string a,string b)
{
    string s;
    int nho=0;
    for (int i=a.size()-1; i>=0; i--)
    {
        int t1=a[i]-'0';
        int t2=b[i]-'0';
        int t=t1+t2+nho;
        if (t<10)
        {
            char tam;
            tam = t+'0';
            s=tam+s;
            nho=0;
        }
        else
        {
            char tam;
            t=t%10;
            tam = t+'0';
            s=tam +s;
            nho=1;
        }
    }
    string kq;
    int i=0;
    while (s[i]=='0')
        i++;
    for (int j=i; j<=s.size()-1; j++)
        kq=kq+s[j];
    if (nho==1) kq='1'+kq;
    return kq;
}
int main()
{
    freopen("SUB.INP","r",stdin);
    freopen("SUB.OUT","w",stdout);
    cin>>n;
    for (int ii=1; ii<=n; ii++)
    {
        string s1,s2,a,b;
        int nho=0;
        char t1,t2;
        cin>>s1;
        cin>>s2;
        if (s1[0]=='-')
            t1=-1;
        else t1=1;
        if (s2[0]=='-')
            t2=-1;
        else t2=1;
        if (s1[0]=='-')
        {
            for (int i=1; i<=s1.size()-1; i++)
                a=a+s1[i];
        }
        else a=s1;
        if (s2[0]=='-')
        {
            for (int i=1; i<=s2.size()-1; i++)
                b=b+s2[i];
        }
        else b=s2;
        if (a.size()!=b.size())
        {
            if (a.size()>b.size())
                while (b.size()<a.size())
                    b='0'+b;
            else
                while (a.size()<b.size())
                    a='0'+a;
        }
        if (t1>0 && t2>0)
        {
            if (a>b) cout<<xulytru(a,b)<<"\n";
            else cout<<"-"<<xulytru(a,b)<<"\n";
        }
        else if (t1>0 && t2<0)
        {
            cout<<xulycong(a,b)<<"\n";
        }
        else if (t1<0 && t2>0)
        {
            cout<<"-"<<xulycong(a,b)<<"\n";
        }
        else if (t1<0 && t2<0)
        {
            if (a>b) cout<<"-"<<xulytru(a,b)<<"\n";
            else cout<<xulytru(a,b)<<"\n";
        }
    }
    return 0;
}
