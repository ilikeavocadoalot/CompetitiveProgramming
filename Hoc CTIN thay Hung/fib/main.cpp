#include <bits/stdc++.h>
using namespace std;
int n;
long long int mu (int x, int y)
{
    long long int t=1;
    for (int i=1; i<=y; i++)
        t=t*x;
    return t;
    /*if (y==1) return 1;
    else return x*mu(x,y-1);*/
}
int main()
{
    n=7;
    cout <<((1/sqrt(5))*(mu(((1+sqrt(5))/2),n) - mu(((1-sqrt(5))/2),n)))<<"\n";
    return 0;
}
