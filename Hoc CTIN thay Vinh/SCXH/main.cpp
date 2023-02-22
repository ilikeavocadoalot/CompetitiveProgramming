/*Cau cho bai AC*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> data;
#define FORW(i,a,b) for(int i=a;i<=b;i++)
#define FORB(i,a,b) for (int i=a;i>=b;i--)
#define forw(i,a,b) for (ll i=a;i<=b;i++)
#define forb(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fr front
#define all(a) a.begin(),a.end()
#define int long long
const ll oo=1e18;
const ll MOD=1e9+7;
const ll mod=1e9+9;
const int  maxN=63;
string a[maxN];

void solve(int n)
{
	int count=1;
	string t;
	stack<string> st;
	bool check[n+1];
	memset(check,false, n+1);
	FORW(i,1,n)
	{
		cin>>t;
		while ((st.empty()||st.top()!=t)&&check[count]==false)
		{

			st.push(a[count]);
			check[count]=true;
			count++;
		}
		if (st.top()==t)
			st.pop();

	}
	cout<<(st.empty()? "Y":"N")<<endl;


}
signed main()
{
	fast;
	freopen("SCXH.INP","r",stdin);
	freopen("SCXH.OUT","w",stdout);
	int n,m;
	cin>>n>>m;
	FORW(i,1,n)
	 cin>>a[i];

	while(m--)
	{
		solve(n);
	}
}




