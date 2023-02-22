#include <bits/stdc++.h>
using namespace std;
struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x)
        , y(y)
        , dis(dis)
    {
    }
};
int trave1 (char t)
{
    if (t=='a') return 1; if (t=='b') return 2; if (t=='c') return 3; if (t=='d') return 4; if (t=='e') return 5;
    if (t=='f') return 6; if (t=='g') return 7; if (t=='h') return 8;
}
int trave2 (char t)
{
    if (t=='1') return 1; if (t=='2') return 2; if (t=='3') return 3; if (t=='4') return 4; if (t=='5') return 5;
    if (t=='6') return 6; if (t=='7') return 7; if (t=='8') return 8;

}
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}
int minStepToReachTarget(int knightPos[], int targetPos[],
                         int N)
{
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    queue<cell> q;
    q.push(cell(knightPos[0], knightPos[1], 0));
    cell t;
    int x, y;
    bool visit[N + 1][N + 1];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
    visit[knightPos[0]][knightPos[1]] = true;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}
int main()
{
    int N = 30;
    freopen("mkm.inp","r",stdin);
    freopen("mkm.out","w",stdout);
    string s1,s2;
    while (cin>>s1>>s2)
    {
        int aa,bb,cc,dd;
        aa=trave1(s1[0]);
        bb=trave2(s1[1]);
        cc=trave1(s2[0]);
        dd=trave2(s2[1]);
        int knightPos[] = { aa, bb };
        int targetPos[] = { cc, dd };
        cout << minStepToReachTarget(knightPos, targetPos, N)<<endl;
        s1=""; s2="";
    }
    return 0;
}
