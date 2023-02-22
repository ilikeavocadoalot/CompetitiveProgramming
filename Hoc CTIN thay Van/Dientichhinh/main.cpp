#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("Dientichhinh.inp","r",stdin);
    freopen("Dientichhinh.out","w",stdout);
    int n;
    cin>>n;
    cout<<"Co "<<n<<" hinh."<<" Loai hinh va Dien tich lan luot la: "<<endl;
    for (int i=1;i<=n;i++)
    {
        string s;
        if (s=="TRON")
        {
            int r;
            cin>>r;
            printf("%s= %.3f",s,float(r)*r*3.14);
        }
        else if (s=="VUONG")
        {
            int a;
            cin>>a;
            cout<<s<<"= "<<float(a)*a;
        }
        else if (s=="HCN")
        {
            int a,b;
            cin>>a>>b;
            cout<<s<<"= "<<float(a)*b;
        }
        cout<<endl;
    }
    return 0;
}
