#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
struct timestruct
{
    int hours = 0;
    int minutes = 0;
    char c = 'a';
};
int main()
{
    int n,h;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        char trash1;
        timestruct t;
        string trash2;
        cin >> t.hours;
        cin >> trash1;
        cin >> t.minutes;
        cin >> t.c;
        cin >> trash2;
        cout<<t.hours<<' '<<trash1<<' '<<t.minutes<<' '<<t.c<<' '<<trash2<<endl;
    }
    return 0;
}
