#include <bits/stdc++.h>
#define inf 1e9+7
using namespace std;
long long l,u,ans1,ans2,ans3,ans4;
void sangtd(long long L,long long R){
    vector<bool> isPrime(R - L + 1, true);
    long long s1=0,s2=0,kq2=-inf,kq1=inf;
    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    }if (1 >= L) {
    isPrime[1 - L] = false;
}
    for (long long x = L; x <= R; ++x) {
        if (isPrime[x - L]) {
            s2=s1;s1=x;
            if (s2!=0){
                if (abs(s1-s2)<kq1){
                    kq1=abs(s1-s2);
                    ans3=s2;
                    ans4=s1;
                }if (abs(s1-s2)>kq2){
                    kq2=abs(s1-s2);
                    ans1=s2;
                    ans2=s1;
                }
            }
        }
}
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);freopen("10140.inp","r",stdin);
    freopen("10140.out","w",stdout);
    while (cin>>l>>u){
        ans1=ans2=ans3=ans4=0;
        sangtd(l,u);
        if ((ans1==0) || (ans2==0) || (ans3==0)|| (ans4==0)) cout<<"There are no adjacent primes.\n";
        else cout<<ans3<<","<<ans4<<" are closest, "<<ans1<<","<<ans2<<" are most distant.\n";
    }
    return 0;
}