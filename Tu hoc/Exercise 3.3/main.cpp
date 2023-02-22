#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    freopen("Vector2.inp","r",stdin);
    freopen("Vector2.out","w",stdout);
    int i,n;
    string s;
    vector <string> v;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>s;
        v.push_back(s);
    }
    v.erase(v.begin()+3);
    v.insert(v.end(),"nothing");
    cout<<v.empty()<<" "<<v.size()<<endl;
    for (auto vt=v.begin();vt!=v.end();vt++)
        cout<<*vt<<endl;
    return 0;
}
