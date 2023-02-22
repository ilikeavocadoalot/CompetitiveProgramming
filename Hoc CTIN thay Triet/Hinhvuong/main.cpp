#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long n,i,j,kq,tam1,tam2;
    long x[2000], y[2000];
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>x[i]>>y[i];
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if ((abs(x[i]-x[j]) == abs(y[i]-y[j]))>kq)
            {
                kq= abs(x[i]-x[j]);
                if (x[i]<x[j])
                {
                    tam1=x[i];
                    tam2=y[i];
                }
                else
                {
                    tam1=x[j];
                    tam2=y[i];
                }
            }
    cout<<tam1<<' '<<tam2<<endl;
    return 0;
}
