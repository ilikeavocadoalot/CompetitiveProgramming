#include <iostream>
#include <stack>
using namespace std;
int main()
{
    long long int n,m;
    freopen("Ralenh.inp","r",stdin);
    freopen("Ralenh.out","w",stdout);
    cin>>n>>m;
    int i;
    for (int tt=0; tt<m; tt++)
    {
        stack <int> rv;
        i=1;
        int k;
        bool kt=true;
        for (int tam=0; tam<n; tam++)
        {
            cin>>k;
            if (k>n)
            {
                kt=false;
                break;
            }
            if (k>=i)
            {
                for (int j=tam; j<k; j++)
                    rv.push(j);
                i=k+1;
            }
            else
            {
                int t=rv.top();
                rv.pop();
                if (t!=k)
                {
                    kt=false;
                    break;
                }
            }
        }
        if (kt) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
