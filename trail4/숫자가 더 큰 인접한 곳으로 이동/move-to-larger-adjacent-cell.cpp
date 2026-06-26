#include <iostream>

using namespace std;

int N;
int map[101][101];

int sy,sx;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void move(int starty,int startx)
{
    int cury = starty;
    int curx = startx;



    while(1)
    {
        printf("%d ",map[cury][curx]);
        int moved = 0;
        for(int dir=0;dir<4;dir++)
        {
            int nexty = cury + dy[dir];
            int nextx = curx + dx[dir];
            if(map[cury][curx] < map[nexty][nextx])
            {
                moved = 1;
                cury += dy[dir];
                curx += dx[dir];
                break;
            }
        }
        if(!moved)
        {
            break;
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &sy, &sx);
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    move(sy,sx);

    return 0;
}