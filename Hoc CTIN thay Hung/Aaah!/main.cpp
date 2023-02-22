#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    if (s1.size()<s2.size()) cout<<"no";
    else cout<<"go";
    return 0;
}
