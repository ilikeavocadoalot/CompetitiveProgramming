#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;
int main()
{
    freopen("Hoanvichuoi.inp","r",stdin);
    freopen("Hoanvichuoi.out","w",stdout);
    string s,p;
    char t;
    queue <char> qu;
    int n,k,tam,dem=0;;
    int a[10000],b[10000];
    cin>>n>>k;
    cin>>s;
    for (int i=0; i<=n; i++)
        a[s[i]]++;
    for (int i=0; i<=k; i++)
    {
        cin>>t;
        tam++;
        qu.push(t);
        b[t]++;
        while (b[t]>a[t])
        {
            b[qu.front()]--;
            qu.pop();
            tam--;
        }
        if (tam==n)
        {
            dem++;
            b[qu.front()]--;
            qu.pop();
            tam--;
        }
    }
    cout<<dem;
    return 0;
}
