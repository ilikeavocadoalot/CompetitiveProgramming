#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int n;
    double w,h;
    cin>>n>>w>>h;
    double k=sqrt((w*w)+(h*h));
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        if (t<=k) cout<<"DA"<<endl;
        else cout<<"NE"<<endl;
    }
    return 0;
}
