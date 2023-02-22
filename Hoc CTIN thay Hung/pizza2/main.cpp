#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    long r,c;
    float t;
    cin>>r>>c;
    t=((float(r-c)*(r-c)*M_PI)/(float(r)*r*M_PI))*100;
    printf("%.6f",t);
    return 0;
}
