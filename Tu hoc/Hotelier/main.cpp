#include <iostream>
#include <vector>
using namespace std;
int doi (char t)
{
    switch (t)
    {
        case '1': return(1);
        case '2': return(2);
        case '3': return(3);
        case '4': return(4);
        case '5': return(5);
        case '6': return(6);
        case '7': return(7);
        case '8': return(8);
        case '9': return(9);
        case '0': return(0);
    }
}
int main()
{
    vector <char> v;
    vector <int> g;
    char t;
    int n,i;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>t;
        v.push_back(t);
    }
    int j;
    for (int it=0; it<10; it++) g.push_back(0);
    for (int it=0; it<n; it++)
    {
        if (v[it]=='L')
        {
            for (j=0; j<10; j++)
                if (g[j]==0) break;
            g[j]=1;
        }
        else if (v[it]=='R')
        {
            for (j=9; j>-1; j--)
                if (g[j]==0) break;
            g[j]=1;
        }
        else g[doi(v[it])]=0;
    }
    for (int it=0; it<10; it++) cout<<g[it];
    return 0;
}
