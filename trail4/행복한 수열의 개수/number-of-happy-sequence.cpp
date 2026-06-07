#include "stdio.h"

int N, M;
int map[100][100];

int main() {
    scanf("%d %d", &N, &M);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    int result = 0;
    int cnt = 0;

    if(M == 1)
    {
      result = 2 * N;
    }
    else 
    {
        // row
        for(int y=0;y<N;y++)
        {
            cnt = 1;
            for(int x=0;x<N-1;x++)
            {
                if(map[y][x] == map[y][x+1])
                {
                    cnt++;
                }
                else
                {
                    cnt = 1;
                }

                if(cnt >= M)
                {
                    result++;
                    break;
                }
            }
        }

        // col
        for(int x=0;x<N;x++)
        {
            cnt = 1;
            for(int y=0;y<N-1;y++)
            {
                if(map[y][x] == map[y+1][x])
                {
                    cnt++;
                }
                else
                {
                    cnt = 1;
                }

                if(cnt >= M)
                {
                    result++;
                    break;
                }            
            }
        }
    }
    printf("%d", result);

    return 0;
}