#include <iostream>
#include <cstdio>
char a[1000][1000];
using namespace std;
bool kt1 (int n)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n/2; j++)
            if (a[i][j]!=a[i][n-j-1]) return(false);
    return(true);
}
bool kt2 (int n)
{
    for (int i=0;i<n/2;i++)
        for (int j=0; j<n; j++)
            if (a[i][j]!=a[n-i-1][j]) return(false);
    return(true);
}
int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin>>a[i][j];
    if (kt1(n) && kt2(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
