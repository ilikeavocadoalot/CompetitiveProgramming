#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector <int> v;
int main()
{
    freopen("Vector1.inp","r",stdin);
    freopen("Vector1.out","w",stdout);
    int n,t,i,value;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>t;
        v.push_back(t);
    }
    for (auto vt=v.rbegin(); vt!=v.rend(); vt++)
    {
        value= *vt;
        cout<<value<<endl;
    }
    return 0;
}
