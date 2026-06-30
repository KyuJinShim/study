#include <iostream>
#include <cstring>

using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int dir = 0;

int N;
int S_Y, S_X;
char map[101][101];
char tmp[101][101];
int ans = 0;
int visited[101][101][4] = {0,};
// 이동 불가능하면 반시계 방향으로 90도
// 이동했다고 가정했을때 방향 기준 오른쪽에 벽이 있으면 이동 가능함
// 이동했다고 가정했을때 방향 기준 오른쪽에 벽이 없으면 이동후 시계방향 90도 만큼 방향을 틀어서 한칸 더 전진
// 이동 가능 및 격자 밖이면 탈출

void print_map()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

void remap()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            map[i][j] = tmp[i][j-1];
        }
    }
}

int move(int s_y, int s_x)
{
    int time = 0;
    while(1)
    {
        visited[s_y][s_x][dir] = true;

        int nexty = s_y + dy[dir];
        int nextx = s_x + dx[dir];

        // 탈출 조건1 : 이동 후 격자 밖 탈출
        if(nexty < 1 || nexty > N || nextx < 1 || nextx > N)
        {
            time++;
            break;
        }
        
        // 현재 상태 중복 검사
        if (visited[nexty][nextx][dir])
            return -1;

        // 이동 불가능
        if(map[nexty][nextx] == '#')
        {
            //반시계 90도
            dir = (dir + 3) % 4;
            if(visited[s_y][s_x][dir]) 
                return -1;
            visited[s_y][s_x][dir] = true;
        }
        else  // 이동 가능 : map[nexty][nextx] == .
        {
            // 이동 가정했을때, 오른쪽 벽 체크
            bool wall_on_right = false;
            int nextnexty = nexty + dy[(dir+1)%4];
            int nextnextx = nextx + dx[(dir+1)%4];

            if(nextnexty >= 1 && nextnexty <= N && nextnextx >= 1 && nextnextx <= N && map[nextnexty][nextnextx] == '#')
            {
                wall_on_right = true;
            }
            
            // 이동
            s_y = nexty;
            s_x = nextx;
            time++;
            visited[s_y][s_x][dir] = true;

            if(wall_on_right == false)
            {
                //90 도 회전
                dir = (dir + 1) % 4;
                nexty = s_y + dy[dir];
                nextx = s_x + dx[dir];
                
                // 이동
                s_y = nexty;
                s_x = nextx;
                time++;
                visited[s_y][s_x][dir] = true;
            }

            // 탈출 조건
            if(s_y < 1 || s_y > N || s_x < 1 || s_x > N) break;
        }
    }
    return time;
}

int main() 
{
    scanf("%d", &N);
    scanf("%d %d", &S_Y, &S_X);    

    for(int i=1;i<=N;i++)
    {
        scanf("%s", tmp[i]);
    }
     
    remap();

    ans = move(S_Y,S_X);

    printf("%d\n", ans);

    return 0;
}