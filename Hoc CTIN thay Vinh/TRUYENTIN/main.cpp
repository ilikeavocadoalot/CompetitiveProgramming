#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,a[1000][1000],cha[1000],con[1000];
int number[1000],low[1000],dem,demcau,demkhop;
void homnayseduocngusom (int u)
{
    dem++;
    number[u]=dem;
    low[u]=n+1;
    for(int v=1;v<=n;v++)
    {
        if(a[u][v]!=0)
        {
			a[v][u]=0;
			if(cha[v]==0)
			{
				cha[v]=u;
				homnayseduocngusom(v);
				low[u]=min(low[u],low[v]);
			}
			else
                low[u]=min(low[u],number[v]);
		}
    }
}
void printresult()
{
	int u,v;
	bool lakhop[1000];
	for(int v=1;v<=n;v++)
	{
		u=cha[v];
		if (u!=-1&&low[v]>=number[v])
			demcau++;
	};
	for(int v=1;v<=n;v++)
		con[v]=0;
	for(int v=1;v<=n;v++)
	{
		u=cha[v];
		if (u!=-1) con[u]++;
	}
	for(int u=1;u<=n;u++)
		lakhop[u]=(cha[u]==-1 && con[u]>=2);
	for(int v=1;v<=n;v++){
		u=cha[v];
		if (u!=-1 && cha[u]!=-1)
			if (low[v]>=number[u])
				lakhop[u]=1;
	}
	for(int u=1;u<=n;u++)
		if (lakhop[u]) demkhop++;
}
int main()
{
    freopen("TRUYENTIN.INP","r",stdin);
    freopen("TRUYENTIN.OUT","w",stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1][t2]=1;
        a[t2][t1]=1;
    }
    dem=0;
	for(int u=1;u<=n;u++) cha[u]=0;
	for(int u=1;u<=n;u++)
    if(cha[u]==0)
    {
        cha[u]=-1;
        homnayseduocngusom(u);
    }
	printresult();
	cout<<demcau<<" "<<demkhop;
    return 0;
}
