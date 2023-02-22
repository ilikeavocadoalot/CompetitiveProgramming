#include <bits/stdc++.h>
using namespace std;
long long l,r,kq1,kq2,kq3,kq4;
void sang(long long left,long long right)
{
    vector <bool> pr(right - left + 1, true);
    long long s1=0,s2=0,kqb=-99999999,kqa=99999999;
    for (long long i = 2; i * i <= right; ++i)
    {
        for (long long j = max(i * i, (left + i - 1) / i * i); j <= right; j += i)
            pr[j - left] = false;
    }
    for (long long x = left; x <= right; ++x)
    {
        if (pr[x - left])
        {
            s2=s1;
            s1=x;
            if (s2!=0)
            {
                if (abs(s1-s2)<kqa)
                {
                    kqa=abs(s1-s2);
                    kq3=s2;
                    kq4=s1;
                }
                if (abs(s1-s2)>kqb)
                {
                    kqb=abs(s1-s2);
                    kq1=s2;
                    kq2=s1;
                }
            }
        }
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("10140.inp","r",stdin);
    freopen("10140.out","w",stdout);
    while (cin>>l>>r)
    {
        kq1=kq2=kq3=kq4=0;
        sang(l,r);
	if ((kq1==0) || (kq2==0) || (kq3==0)|| (kq4==0))
		cout<<"There are no adjacent primes.\n";
        else
		cout<<kq3<<","<<kq4<<" are closest, "<<kq1<<","<<kq2<<" are most distant.\n";
    }
    return 0;
}
