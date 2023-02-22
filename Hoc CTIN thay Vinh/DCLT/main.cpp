#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int b[100005],tong;
int tam;
int main()
{
    freopen("DCLT.INP","r",stdin);
    freopen("DCLT.OUT","w",stdout);
    queue <int> mang;
    int dem=0,ans=0,n,k;
    cin>>k>>n;
    for (int i=0;i<k;i++)
    {
        cin>>tam;
        b[tam]++;
        mang.push(tam);
        dem++;
        tong=tong+tam;
        while (tong>n)
        {
            b[mang.front()]--;
            dem--;
            tong=tong-mang.front();
            mang.pop();
        }
        if (tong==n)
        {
            ans++;
            dem--;
            b[mang.front()]--;
            tong=tong-mang.front();
            mang.pop();
        }
    }
    cout<<ans;
    return 0;
}
