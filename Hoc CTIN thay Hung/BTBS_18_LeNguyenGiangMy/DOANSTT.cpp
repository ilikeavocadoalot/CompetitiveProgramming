#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=110;

int n,map[N][N],x[N][2],y[N][2],num[N][2];
int linker[N],vis[N];

int DFS(int u){
    int v;
    for(v=1;v<=n;v++)
        if(map[u][v] && !vis[v]){
            vis[v]=1;
            if(linker[v]==-1 || DFS(linker[v])){
                linker[v]=u;
                return 1;
            }
        }
    return 0;
}

int Hungary(){
    int u,ans=0;
    memset(linker,-1,sizeof(linker));
    for(u=1;u<=n;u++){
        memset(vis,0,sizeof(vis));
        if(DFS(u))
            ans++;
    }
    return ans;
}

int main(){
	freopen("doanstt.inp","r",stdin);
	freopen("doanstt.out","w",stdout);
    int cases=0;
    while(~scanf("%d",&n) && n){
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
            scanf("%d%d%d%d",&x[i][0],&x[i][1],&y[i][0],&y[i][1]);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&num[i][0],&num[i][1]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(num[i][0]>=x[j][0] && num[i][0]<=x[j][1] && num[i][1]>=y[j][0] && num[i][1]<=y[j][1])
                    map[i][j]=1;
        printf("Heap %d\n",++cases);
        int flag=0;
        for(int j=1;j<=n;j++)
            for(int i=1;i<=n;i++){
                if(map[i][j]==0)
                    continue;
                map[i][j]=0;
                if(Hungary()<n){
                    flag=1;
                    char ch='A'+(j-1);
                    printf("(%c,%d)",ch,i);
                }
                map[i][j]=1;
            }
        if(!flag)
            printf("none\n\n");
        else
            printf("\n\n");
    }
    return 0;
}