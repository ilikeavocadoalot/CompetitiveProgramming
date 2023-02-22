#include <bits/stdc++.h>
using namespace std;
string a[10000];
int main()
{
    int t=2,n,k=0;
    cin>>n;
    a[0]="0";
    a[1]="1";
    while (a[k].length()<n)
    {
        a[t++]=a[k]+"0";
        a[t++]=a[k]+"1";
        k++;

    }
    for (int i=k; i<t; i++)
        cout<<a[i]<<endl;
    return 0;
}
