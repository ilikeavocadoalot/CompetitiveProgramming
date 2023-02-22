#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("STR1.INP","r",stdin);
    freopen("STR1.OUT","w",stdout);
    string s;
    int dem=0;
    while (cin>>s)
    {
        dem++;
    }
    cout<<dem<<endl;
    return 0;
}
