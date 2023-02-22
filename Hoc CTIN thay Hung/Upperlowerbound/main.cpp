#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return(a>b);
}
int main ()
{
    vector <int> v ={10,10,30,30,30,100,10,300,300,70,70,80};
    pair <vector<int>::iterator, vector <int>::iterator> ip;
    sort(v.begin(),v.end(),greater<int>());
    ip=equal_range(v.begin(),v.begin()+12,10,comp);
    cout<<"10 is present in the sorted vector from index ";
    cout<<(ip.first-v.begin())<<" till "<<(ip.second-v.begin());
    return 0;
}
