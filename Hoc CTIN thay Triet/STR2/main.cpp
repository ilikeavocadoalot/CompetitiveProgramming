#include <iostream>
using namespace std;
int main()
{
    freopen("STR2.INP","r",stdin);
    freopen("STR2.OUT","w",stdout);
    string s;
    while (getline(cin,s))
    {
        int dem=0;
        s=' '+s;
        s=' '+s;
        for (int i=0; i<=s.size()-2; i++)
        {
            if ((s[i]==' ') && (s[i+1]!=' '))
                dem++;
        }
        cout<<dem<<endl;
    }
}


