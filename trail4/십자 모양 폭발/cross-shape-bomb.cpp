#include <iostream>

using namespace std;

int N;
int map[201][201];
int tmp[201][201] = {0,};
int Y,X;
int power = 0;

int main() {
    scanf("%d", &N);

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d %d", &Y, &X);

    power = map[Y][X] - 1;
 
    // bomb
    map[Y][X] = 0;
    for(int i=1;i<=power;i++)
    {
        if(X-i >= 1)
            map[Y][X-i] = 0;
        if(X+i <= N)
            map[Y][X+i] = 0;
        if(Y+i <= N)
            map[Y+i][X] = 0;
        if(Y-i >= 1)
            map[Y-i][X] = 0;
    }

    // gravity
    for(int x=1;x<=N;x++)
    {
        int idx = N;

        for(int y=N;y>=1;y--)
        {
            if(map[y][x] != 0)
            {
                tmp[idx--][x] = map[y][x];
            }
        }
    }
    

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }


    return 0;
}
