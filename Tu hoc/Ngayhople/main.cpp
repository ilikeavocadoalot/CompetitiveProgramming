#include <iostream>
using namespace std;
bool hople (int d, int m, int y)
{
    bool kt=false;
    if ((y%400==0)||((y%4==0)&&(y%100!=0))) kt=true;
    switch (m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if ((d<=30)&&(d>0)) return(true);
            else return(false);
        }
        break;
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if((d<=30)&&(d>0)) return (true);
            else return(false);
        }
        break;
        case 2:
        {
            if (kt==true)
            {
                if ((d<=29)&&(d>0)) return(true);
                else return(false);
            }
            else
            {
                if((d<=28)&&(d>0)) return(true);
                else return(false);
            }
        }
        break;
        default: return(false);
    }
}
int main()
{
    int ng,th,na;
    cin>>ng>>th>>na;
    if (hople(ng,th,na)==true)
        cout<<"Ngay hop le";
    else cout<<"Ngay khong hop le";
}
