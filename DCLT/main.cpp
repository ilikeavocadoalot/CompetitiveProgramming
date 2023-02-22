#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int b[100005],tong;
long long int tam;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("DCLT.INP","r",stdin);
    freopen("DCLT.OUT","w",stdout);
    queue <long long int> mang;
    long long int dem=0,kq=0,n,k;
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
            kq++;
            dem--;
            b[mang.front()]--;
            tong=tong-mang.front();
            mang.pop();
        }
    }
    cout<<kq;
    return 0;
}
