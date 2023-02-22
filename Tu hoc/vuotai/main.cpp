#include <iostream>
using namespace std;
int ma(int a,int b)
{
    if (b<0) return 0;
    if (b>a) return b;
    else return 0;
}
int main()
{
    int n,i,m=-99999999,k,a[100000];
    long long int s=0;
    cin>>n>>k;
    for (i=0; i<n; i++)
    {
        cin>>a[i];
        s+=a[i];
        if (a[i]>m) m=a[i];
    }
    s-=m;
    s+= ma(0,m-k);
    s+=1;
    cout<<s;
    return 0;
}
