#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>

using namespace std;

int N;
int map[20][20];

int ans = 0;

int dy[4] = {-1,-1,1,1};
int dx[4] = {1,-1,-1,1};
int len[4] = {0,};

int solve(int start_i, int start_j, int a, int b)
{
    int cur_i = start_i;
    int cur_j = start_j;
    int sum = 0;

    len[0] = a;
    len[1] = b;
    len[2] = a;
    len[3] = b;

    for(int dir=0;dir<4;dir++)
    {
        for(int k=0;k<len[dir];k++)
        {
            cur_i += dy[dir];
            cur_j += dx[dir];

            if(cur_i < 0 || cur_i >= N || cur_j < 0 || cur_j >=N)
                return -1;

            sum += map[cur_i][cur_j];
        }
    }

    if((cur_i == start_i) && (cur_j == start_j))
        return sum;
    else 
        return -1;
}

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int a=1;a<N;a++)
            {
                for(int b=1;b<N;b++)
                {
                    int ret = solve(i,j,a,b);
                    if(ret != -1)
                    {
                        ans = max(ans,ret);
                    }
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}