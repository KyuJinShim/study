#include <iostream>
using namespace std;

int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int dx[9] = {0,0,1,1,1,0,-1,-1,-1};

int map[4][4];
int dir_map[4][4];
int N, Y, X;
int ans = 0;

void solve(int depth, int y, int x)
{
    ans = max(ans, depth);

    for(int i=1;i<=N;i++)
    {
        int ny = y + dy[dir_map[y][x]] * i;
        int nx = x + dx[dir_map[y][x]] * i;

        if(ny < 1 || ny > N || nx < 1 || nx > N)
            continue;
        
        if(map[y][x] < map[ny][nx])
            solve(depth+1, ny, nx);
    }
}
int main() {
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d ", &map[i][j]);
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d ",&dir_map[i][j]);
        }
    }
    cin >> Y >> X;

    solve(0,Y,X);

    printf("%d\n", ans);
    
    return 0;
}