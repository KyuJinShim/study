#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[21][21]; 

struct Pos{
    int y;
    int x;
};

int dy[8] = {-1,-1,-1,0,1,1,1,0};
int dx[8] = {-1,0,1,1,1,0,-1,-1};

int main() {
    scanf("%d %d", &N, &M);

    vector<Pos> Num(N*N+1);

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d", &map[i][j]);
            Num[map[i][j]].y = i;
            Num[map[i][j]].x = j;
        }
    }

    for(int m=0;m<M;m++)
    {
        for(int n=1;n<=N*N;n++)
        {
            int max_n = -1e9;
            int cur_y = Num[n].y;
            int cur_x = Num[n].x;
            int move_y = 0;
            int move_x = 0;
            for(int dir=0;dir<8;dir++)
            {
                int checky = cur_y + dy[dir];
                int checkx = cur_x + dx[dir];
                
                if(checky < 1 || checky > N || checkx < 1 || checkx > N) continue;

                if(map[checky][checkx] > max_n)
                {
                    max_n = map[checky][checkx];
                    move_y = checky;
                    move_x = checkx;
                }
            }
            map[cur_y][cur_x] = max_n;
            map[move_y][move_x] = n;
            Num[max_n].y = cur_y;
            Num[max_n].x = cur_x;
            Num[n].y = move_y;
            Num[n].x = move_x;   
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }

    return 0;
}