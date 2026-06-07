#include "stdio.h"
#include <cstring>
#include "math.h"
#include "stdlib.h"

using namespace std;

int N, M;
int map[20][20];

int gold_cnt;
int gold_price_total;
int cost;

int calculate_cost(int k)
{
    return ((k*k) + (k+1)*(k+1));
}

void solve(int cy, int cx, int k)
{
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            if((abs(y-cy) + abs(x-cx) <= k))
            {
                gold_cnt += map[y][x];
            }
        }
    }

}

int main() {
    int ans = 0;

    scanf("%d %d", &N, &M);

    for(int i=0; i<N;i++)
    {
       for(int j=0;j<N;j++)
       {
         scanf("%d", &map[i][j]);
       }   
    }

    for(int k=0;k<2*N;k++)
    {
        cost = calculate_cost(k);

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
              gold_cnt = 0;

              solve(i, j, k);

              gold_price_total = gold_cnt * M;
              if(gold_price_total >= cost)
              {
                 if(ans < gold_cnt)
                 {
                    ans = gold_cnt;
                 }
              }
            }
        }
    }

    printf("%d", ans);

    return 0;
}