#include <iostream>
#include <stack>
using namespace std;
int main()
{
    freopen ("Daysonguyen.inp","r",stdin);
    freopen ("Daysonguyen.out","w",stdout);
    stack <long long int> cs;
    int f[100010],a[100010];
    bool b[100010];
    long long int n,t;
    cin>>n,t;
    int i=1;
    for (int i=0; i<=n+1; i++)
        b[i]=false;
    while (i<=n)
    {
        if (b[i]==false)
        {
            cin>>a[i];
            b[i]=true;
        }
        if (cs.empty() || a[i]<=a[cs.top()])
        {
            cs.push(i);
            i++;
        }
        else
        {
            f[cs.top()]=i;
            cs.pop();
        }
    }
    for (int i=1; i<=n; i++)
        cout<<f[i]<<endl;
    return 0;
}
