#include <iostream>
using namespace std;

int N,M; // N * M
int map[101][101];
int Q;

int R1,C1;
int R2,C2;

void copy_map(int tmp_map[101][101])
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            tmp_map[i][j] = map[i][j];
        }
    }
}

void average(int r1, int c1, int r2, int c2)
{
    int average_map[101][101] ={0,};
    int average = 0;

    for(int y=r1;y<=r2;y++)
    {
        for(int x=c1;x<=c2;x++)
        {
            int n = 1;
            int sum = map[y][x];
            //up
            if(y-1 >= 1)
            {
                sum += map[y-1][x];
                n++;
            }
            //right
            if(x+1 <= M)
            {
                sum += map[y][x+1];
                n++;
            }
            //down
            if(y+1 <= N)
            {
                sum += map[y+1][x];
                n++;
            }
            //left
            if(x-1 >= 1)
            {
                sum += map[y][x-1];
                n++;
            }

            average = (int)(sum/n);
            average_map[y][x] = average;
        }
    }

    for(int y=r1;y<=r2;y++)
    {
        for(int x=c1;x<=c2;x++)
        {
            map[y][x] = average_map[y][x];
        }
    }
}

void rotate(int r1, int c1, int r2, int c2, int tmp_map[101][101])
{
    // ->
    for(int x=c1+1;x<=c2;x++)
    {
        map[r1][x] = tmp_map[r1][x-1];
    }
    map[r1][c1] = tmp_map[r1+1][c1];

    // down
    for(int y=r1+1;y<=r2;y++)
    {
        map[y][c2] = tmp_map[y-1][c2];
    }
    map[r1][c2] = tmp_map[r1][c2-1];

    // <-
    for(int x=c2-1;x>=c1;x--)
    {
        map[r2][x] = tmp_map[r2][x+1];
    }
    map[r2][c2] = tmp_map[r2-1][c2];

    // up
    for(int y=r2-1;y>=r1;y--)
    {
        map[y][c1] = tmp_map[y+1][c1];
    }
    map[r2][c1] = tmp_map[r2][c1+1];
}

int main() {
    scanf("%d %d %d", &N, &M, &Q);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for(int q=0;q<Q;q++)
    {
        scanf("%d %d %d %d", &R1, &C1, &R2, &C2);
        
        int tmp_map[101][101] = {0,};
        
        //copy map -> tmp_map;
        copy_map(tmp_map);

        //rotate map
        rotate(R1, C1, R2, C2, tmp_map);

        //get average
        average(R1,C1,R2,C2);
    }

    for(int y=1;y<=N;y++)
    {
        for(int x=1;x<=M;x++)
        {
            printf("%d ", map[y][x]);
        }
        printf("\n");
    }
    return 0;
}