#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    priority_queue <int> pq;
    int n,t2,m,t,tam=0,tmp=0,ma,dem=0,kt=0,a[1000],b[1000];
    while (cin>>m)
    {
        cin>>t;
        if (t==1)
        {
            cin>>t2;

            if (a[tmp]>ma) ma=a[tmp];
        }
        else
        {
            cin>>b[tam];
            tam++;
        }
        }
        if (a[0]==b[0])
        {
            kt=1;
            dem++;
        }
        if (a[tmp-1]==b[0])
        {
            kt=2;
            dem++;
        }
        if (b[0]==ma)
        {
            kt=3;
            dem++;
        }
        if (dem==0) cout<<'impossible'<<endl;
        else if (kt==1) cout<<'queue'<<endl;
        else if (kt==2) cout<<'stack'<<endl;
        else if (kt==3) cout<<'priority queue'<<endl;
        else if (dem>1) cout<<'not sure'<<endl;
    }
    return 0;
}
