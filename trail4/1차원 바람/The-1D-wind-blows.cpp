#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int N, M; // N * M map
int map[101][101];
int Q; // number of wind

struct Wind{
    int r;
    char d;
};

Wind wind[102];

void backup(int row, int* tmp_row)
{
    for(int i=1;i<=M;i++)
    {
        tmp_row[i] = map[row][i];
    }
}

void move(int row, char dir, int* tmp_row)
{
    // blow wind
    if(dir == 'L')
    {
        //move right
        for(int x=2;x<=M;x++)
        {
            map[row][x] = tmp_row[x-1];
        }
        map[row][1] = tmp_row[M];
    }
    else if(dir == 'R')
    {
        //move left
        for(int x=1;x<=M-1;x++)
        {
            map[row][x] = tmp_row[x+1];
        }
        map[row][M] = tmp_row[1];
    }
}

int check(int a, int b)
{
    int ret = 0;
    for(int i=1;i<=M;i++)
    {
        if(map[a][i] == map[b][i])
        {
            ret = 1;
        }
    }
    return ret;
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


    for(int q=1;q<=Q;q++)
    {
        scanf("%d %c", &wind[q].r, &wind[q].d);
    }

    for(int q=1;q<=Q;q++)
    {
        int main_row = wind[q].r;
        char wind_dir = wind[q].d;
        int tmp_row[101] = {0,};
        
        // backup main row
        memset(tmp_row, 0, sizeof(tmp_row));
        backup(main_row, tmp_row);
        // move main row
        move(main_row,wind_dir,tmp_row);

        //up row check
        if(main_row >= 1)
        {
            char cur_wind_dir = wind_dir;
            for(int i=main_row-1;i>=1;i--)
            {
                int flag = 0;
                flag = check(i,i+1);
                
                if(!flag) break;

                // wind blow other direction
                if(flag)
                {
                    //backup row i
                    memset(tmp_row, 0, sizeof(tmp_row));
                    backup(i, tmp_row);

                    if(cur_wind_dir == 'L')
                    {
                        move(i,'R',tmp_row);
                        cur_wind_dir = 'R';
                    }
                    else if(cur_wind_dir == 'R')
                    {
                        move(i,'L',tmp_row);
                        cur_wind_dir = 'L';
                    }
                }
            }
        }

        //down row check
        if(main_row <= N)
        {
            char cur_wind_dir = wind_dir;
            for(int i=main_row+1;i<=N;i++)
            {               
                int flag = 0;

                flag = check(i,i-1);
                if(!flag) break;
                    
                // wind blow other direction
                if(flag)
                {
                    //backup row i
                    memset(tmp_row, 0, sizeof(tmp_row));
                    backup(i, tmp_row);

                    if(cur_wind_dir == 'L')
                    {
                        move(i,'R',tmp_row);
                        cur_wind_dir = 'R';
                    }
                    else if(cur_wind_dir == 'R')
                    {
                        move(i,'L',tmp_row);
                        cur_wind_dir = 'L';
                    }
                }
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}