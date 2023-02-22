#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("Xau.inp","r",stdin);
    freopen("Xau.out","w",stdout);
    string s;
    int i=0;
    while (getline(cin,s))
    {
        i++;
        cout<<"dong "<<i<<"="<<s<<endl;
    }
}
