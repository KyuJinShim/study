#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int c;
int map[201][201];
int C[11];

int main() 
{
    scanf("%d %d" ,&N, &M);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i=1;i<=M;i++)
    {
        scanf("%d", &C[i]);
    }  

    for(int t=1;t<=M;t++)
    {
        int tmp[201][201] = {0,};
        
        // get col
        int c = C[t];
        
        // get row
        int r = 0;

        for(int i=1;i<=N;i++)
        {
            if(map[i][c] != 0)
            {
                r = i;
                break;
            }
        }
        
        int power = map[r][c] - 1;
        map[r][c] = 0;

        // set zero
        if(power >= 1)
        {
            for(int i=1;i<=power;i++)
            {
                if(r-i >= 1)
                {
                    map[r-i][c] = 0;
                }
                if(r+i <= N)
                {
                    map[r+i][c] = 0;
                }
                if(c-i >= 1)
                {
                    map[r][c-i] = 0;
                }
                if(c+i <= N)
                {
                    map[r][c+i] = 0;
                }
            }
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
        
        memset(map,0,sizeof(map));

        // copy tmp -> map
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                map[i][j] = tmp[i][j];
            }
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