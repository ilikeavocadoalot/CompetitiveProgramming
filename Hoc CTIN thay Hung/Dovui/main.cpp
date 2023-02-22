#include <iostream>
using namespace std;
int kwh(long long int a)
{
    if (a<=200)
        return (a/2);
    else if (a<=100*2+9900*3)
        return (100+((a-200)/3));
    else if (a<=100*2+9900*3+990000*5)
        return (100+9900+(a-100*2-9900*3)/5);
    else return(100+9900+990000+(a-100*2-9900*3-990000*5)/7);
}
int tien(long long int b)
{
    if (b<=100)
        return (b*2);
    else if (b<=10000)
        return (200+((b-100)*3));
    else if (b<=1000000)
        return (200+3*9900+(b-10000)*5);
    else return(990000*5+9900*3+100*2+(b-1000000)*7);
}
int main()
{
    freopen("Dovui.inp","r",stdin);
    freopen("Dovui.out","w",stdout);
    long long int a,b;
    cin>>a>>b;
    long long int tam;
    tam=kwh(a);
    long long int t1,t2;
    for (int i=tam/2; i>0; i--)
        if (abs(tien(i)-tien(tam-i))==b)
        {
            cout<<tien(i);
            return 0;
        }
}
