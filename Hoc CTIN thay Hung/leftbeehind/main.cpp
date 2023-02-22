#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int x,y;
    while (true)
    {
        cin>>x>>y;
        if ((x==0) && (y==0)) return 0;
        if (x+y==13)
        {
            cout<<"Never speak again."<<endl;
            continue;
        }
        if (x>y)
        {
            cout<<"To the convention."<<endl;
            continue;
        }
        if (x==y)
        {
            cout<<"Undecided."<<endl;
            continue;
        }
        if (x<y)
        {
            cout<<"Left beehind."<<endl;
            continue;
        }
    }
}
