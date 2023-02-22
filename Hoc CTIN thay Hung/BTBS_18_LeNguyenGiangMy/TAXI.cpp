#include <bits/stdc++.h>

using namespace std;

int m;
int ptd[501][501];
int B[501], link[501];

struct node
{
	int a, b, c, d;
	int tt;
}taxi[501];

int find(int v)
{
	int i;

	for(i = 1; i <= m; i++)
		if(ptd[v][i]&&!B[i])
		{
			B[i] = 1;
			if(!link[i]||find(link[i]))
			{
				link[i] = v;
				return 1;
			}
		}
	return 0;
}

void input()
{
	int i, j, tt;
	int hh, mm, ans;

	scanf("%d",&m);
	for(i = 1; i <= m; i++)
	{
		scanf("%d:%d%d%d%d%d",&hh,&mm,&taxi[i].a,&taxi[i].b,&taxi[i].c,&taxi[i].d);
		tt = hh*60+mm;
		taxi[i].tt = tt;
	}
	memset(ptd,0,sizeof(ptd));
	for(i = 1; i < m; i++)
		for(j = i+1; j <= m; j++)
			if(taxi[i].tt+abs(taxi[i].a-taxi[i].c)+abs(taxi[i].b-taxi[i].d)+abs(taxi[i].c-taxi[j].a)+abs(taxi[i].d-taxi[j].b)<taxi[j].tt)
				ptd[i][j] = 1;
	ans = 0;
	memset(link,0,sizeof(link));
	for(i = 1; i <= m; i++)
	{
		memset(B,0,sizeof(B));
		ans += find(i);
	}
	printf("%d\n",m-ans);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    freopen("taxi.inp","r",stdin);
    freopen("taxi.out","w",stdout);
    int n;
	scanf("%d",&n);
	while(n--)
		input();
	return 0;
}