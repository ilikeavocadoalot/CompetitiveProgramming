#include <bits/stdc++.h>
using namespace std;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define MAX 1000000
int t;
string s;
int main()
{
    freopen("11955.INP","r",stdin);
    freopen("11955.OUT","w",stdout);
	cin>>t;
    for (int index=1; index<=t; index++)
	{
		string s, temp = "";
		string t1, t2, t3;
		cin>>s;
		for (int i=1; i<s.size(); i++)
		{
			if(s[i] == '(' || s[i] == ' ')
				continue;
			else if(s[i] == '+')
            {
				t1 = temp;
				temp = "";
			}
			else if(s[i] == ')')
			{
				t2 = temp;
				temp = "";
			}
			else if(s[i] == '^')
				continue;
			else
				temp += s[i];
		}
		t3 = temp;
		int k  = atoi(t3.c_str());
        int c[k+1];
        c[0]=1;
        for (int i=1; i<=k; i++)
            c[i]=(c[i-1]*(k-i+1))/i;
        cout<<"Case "<<index<<": ";
        for (int i=0; i<=k; i++)
		{
			if( c[i] > 1 )
				cout<<c[i]<<"*";
			if(k - i > 0)
				cout<<t1;
			if(k - i > 1)
				cout<<"^"<<k-i;
			if((c[i] > 1 || k - i > 0) && i > 0)
				cout<<"*";
			if(i > 0)
				cout<<t2;
			if(i > 1)
				cout<<"^"<<i;
			if(i < k)
				cout<<"+";
		}
		cout<<"\n";
	}
	return 0;
}
