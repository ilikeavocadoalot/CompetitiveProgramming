#include <bits/stdc++.h>
using namespace std;
int n,a[1000],kv1[1000],kv2[1000],kv3[1000],kv4[1000],kv5[1000],kv0[1000];
int main()
{
    freopen("bee.inp","r",stdin);
    freopen("bee.out","w",stdout);
    kv0[1]=1; kv1[1]=1; kv2[1]=1; kv3[1]=1; kv4[1]=1; kv5[1]=1;
    int tam=1;
    int vong,tongtrc,tongsau;
    tongtrc=1;
    tongsau;
    for (int i=1; i<=1000; i++)
    {
        tongsau = tongtrc + (i-1)*6 + tam;
        kv0[i+1]=tongsau;
        tongtrc = tongsau;
    }
    tam=2;
    tongtrc=1;
    for (int i=1; i<=1000; i++)
    {
        tongsau = tongtrc + (i-1)*6 + tam;
        kv1[i+1]=tongsau;
        tongtrc = tongsau;
    }
    tam=3;
    tongtrc=1;
    for (int i=1; i<=1000; i++)
    {
        tongsau = tongtrc + (i-1)*6 + tam;
        kv2[i+1]=tongsau;
        tongtrc = tongsau;
    }
    tam=4;
    tongtrc=1;
    for (int i=1; i<=1000; i++)
    {
        tongsau = tongtrc + (i-1)*6 + tam;
        kv3[i+1]=tongsau;
        tongtrc = tongsau;
    }
    tam=5;
    tongtrc=1;
    for (int i=1; i<=1000; i++)
    {
        tongsau = tongtrc + (i-1)*6 + tam;
        kv4[i+1]=tongsau;
        tongtrc = tongsau;
    }
    tam=6;
    tongtrc=1;
    for (int i=1; i<=1000; i++)
    {
        tongsau = tongtrc + (i-1)*6 + tam;
        kv5[i+1]=tongsau;
        tongtrc = tongsau;
    }
    a[0]=0;
    int tmp=1;
    for (int index=1; index<=1000; index++)
    {
        a[index]=tmp;
        tmp+=6*index;
    }
    while (cin>>n)
    {
        for (int i=1; i<=1000; i++)
        {
            if (n>a[i-1] && n<=a[i])
            {
                vong=i;
                break;
            }
        }
        if (n==1) cout<<0<<" "<<0<<endl;
        else
        {
            if (kv0[vong]==n) cout<<0<<" "<<vong-1<<endl;
            if (kv1[vong]==n) cout<<-(vong-1)<<" "<<vong-1<<endl;
            if (kv2[vong]==n) cout<<-(vong-1)<<" "<<0<<endl;
            if (kv3[vong]==n) cout<<0<<" "<<-(vong-1)<<endl;
            if (kv4[vong]==n) cout<<vong-1<<" "<<-(vong-1)<<endl;
            if (kv5[vong]==n) cout<<vong-1<<" "<<0<<endl;
            if (n>kv0[vong] && n<kv1[vong])
                cout<<-(n-kv0[vong])<<" "<<vong-1<<endl;
            if (n>kv1[vong] && n<kv2[vong])
                cout<<-(vong-1)<<" "<<(kv2[vong]-n)<<endl;
            if (n>kv2[vong] && n<kv3[vong])
                cout<<-(kv3[vong]-n)<<" "<<-(n-kv2[vong])<<endl;
            if (n>kv3[vong] && n<kv4[vong])
                cout<<(n-kv3[vong])<<" "<<-(vong-1)<<endl;
            if (n>kv4[vong] && n<kv5[vong])
                cout<<vong-1<<" "<<-(kv5[vong]-n)<<endl;
            if (n>kv5[vong-1] && n<kv0[vong])
                cout<<(kv0[vong]-n)<<" "<<(n-kv5[vong-1])<<endl;
            }
    }
}
