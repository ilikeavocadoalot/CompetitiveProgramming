#include <bits/stdc++.h>
using namespace std;
int stringToNum(char c)
{
    return c - '0';
}
char numToString(int n)
{
    return (char)(n+48);
}
int a[10000];
string nhan (string s1, string s2)
{
    int nho=0;
    string s3="";
    int tam=0;
    memset(a,0,sizeof(a));
    for (int i=s1.size()-1; i>=0; i--)
    {
        int t1=stringToNum(s1[i]);
        for (int j=s2.size()-1; j>=0; j--)
        {
            int t2=stringToNum(s2[j]);
            tam = t1*t2+nho;
            nho=0;
            if (tam>9)
            {
                a[s2.size()-j+s1.size()-i-2]+=(tam%10);
                nho=tam/10;
            }
            else
            {
                a[s2.size()-j+s1.size()-i-2]+=tam;
            }
            if (a[s2.size()-j+s1.size()-i-2]>9)
            {
                a[s2.size()-j+s1.size()-i-2]=a[s2.size()-j+s1.size()-i-2]%10;
                nho++;
            }
        }
        a[s2.size()+s1.size()-1-i]+=nho;
        nho=0;
    }
    tam=0;
    for (int k=0; k<s1.size()+s2.size()-tam; k++)
    {
        char tmp=numToString(a[k]);
        s3=s3+tmp;
        a[k]=0;
    }
    string s4;
    for (int k=s3.size()-1; k>=0; k--)
        s4=s4+s3[k];
    string s5;
    int j=0;
    while (s4[j]=='0') j++;
    for (int k=j; k<=s4.size()-1; k++)
        s5=s5+s4[k];
    return s5;
}
int main()
{
    freopen("NHAN.INP","r",stdin);
    freopen("NHAN.OUT","w",stdout);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        string s1,s2;
        cin>>s1;
        cin>>s2;
        cout<<nhan(s1,s2)<<"\n";
    }
    return 0;
}
