#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("Sothuc.inp","r",stdin);
    freopen("Sothuc.out","w",stdout);
    long a,b;
    cin >>a>>b;
    printf("%.2f %.3f",double(a)/b,double(a+b)/b);
    return 0;
}
