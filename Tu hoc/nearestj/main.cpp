#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++)
    {
        stack <long long int> cs;
        int f[100010],a[100010];
        bool b[100010];
        long long int n;
        cin>>n;
        int i=1;
        for (int i=0; i<=n+1; i++)
            b[i]=false;
        for (int i=0; i<=n+1; i++)
            f[i]=0;
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
            if (f[i]!=0) cout<<a[f[i]]<<" ";
            else cout<<-1<<" ";
        cout<<endl;
    }
    return 0;
}
