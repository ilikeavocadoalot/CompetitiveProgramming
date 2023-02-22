#include <bits/stdc++.h>
using namespace std;
int main()
{
    set <int> s;
    s.insert(4);
    s.insert(7);
    s.insert(1);
    auto it=s.find(4);
    ++it;
    cout<<*it<<endl;
    if (s.find(7)==s.end())
        cout<<"7 is not in the set" <<endl;
    s.erase(7);
    if (s.find(7) == s.end())
        cout<<"7 is not in the set"<<endl;
    cout<<"The smallest element of s is " <<*s.begin()<<endl;
    return 0;
}
