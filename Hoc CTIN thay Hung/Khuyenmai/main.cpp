#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <long long int> b,c,t1,t2,a;
long long int tenkhonghopphongthuy;
long long int n,m,tong=0,k,dem=0;
void sinhlacaigizthay (vector <long long int> &t, vector <long long int> &ma, long long int tam)
{
    string v,s;
    int i;
    for (i=0; i<tam; i++)
        s=s+'0';
    v=s;
    do
    {
        i=tam-1;
        while ((i>=0) && (v[i]=='1'))
        {
            v[i]='0';
            i--;
        }
        v[i]='1';
        tong=0;
        for (int i=0; i<tam; i++)
            if (v[i]=='1')
                tong=tong+t[i];
        ma.push_back(tong);
    } while (v.compare(s)==1);
}
int main()
{
    freopen("Khuyenmai.inp","r",stdin);
    freopen("Khuyenmai.out","w",stdout);
    cin>>n>>m;
    k=n/2;
    for (int i=0; i<n; i++)
    {
        cin>>tenkhonghopphongthuy;
        a.push_back(tenkhonghopphongthuy);
    }
    for (int i=0; i<k; i++)
        t1.push_back(a[i]);
    for (int i=k; i<=n; i++)
        t2.push_back(a[i]);
    sinhlacaigizthay (t1,b,k);
    sinhlacaigizthay (t2,c,k+1);
    sort (b.begin(),b.end());
    for (int i=0; i<c.size(); i++)
        dem += (upper_bound (b.begin(),b.end(),m-c[i])-b.begin());
    cout<<dem;
    return 0;
}
