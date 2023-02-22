#include <iostream>
#include <stack>
using namespace std;
int main()
{
    freopen("SCXH.INP","r",stdin);
    freopen("SCXH.OUT","w",stdout);
    string a[10000];
    long long int n,t;
    cin>>n>>t;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=1; i<t; i++)
    {
        stack <string> rv;
        bool kt[10000];
        for (int j=0; j<n+1; j++) kt[j]=false;
        string k;
        int tam=0;
        for (int j=0; j<n; j++)
        {
            cin>>k;
            while ((kt[tam]==false) && ((rv.empty())||(rv.top()!=k)))
            {
                rv.push(a[tam]);
                kt[tam]=true;
                tam++;
            }
            if (rv.top()==k) rv.pop();
        }
        if (rv.empty()) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}
