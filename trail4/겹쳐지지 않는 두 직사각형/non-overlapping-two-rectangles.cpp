#include <iostream>
#include "stdio.h"
#include <algorithm>

using namespace std;

int N;
int M;
int ans = -1001;
int map[5][5];

int solve(int h_1, int w_1, int h_2, int w_2)
{
    int sum = 0;
    int maxx = -1001;
                    
    for(int y_1=0;y_1<N;y_1++)
    {
        for(int x_1=0; x_1<M; x_1++)
        {
            for(int y_2=0;y_2<N;y_2++)
            {
                for(int x_2=0;x_2<M;x_2++)
                {        
                    sum = 0;
                    if(y_1+h_1>=N+1 || x_1+w_1>=M+1)
                    {
                      //  printf("1 :[y_1 :%d][x_1 :%d][y_2 :%d][x_2 :%d]\n[h_1 : %d][w_1 : %d][h_2 : %d][w_2 : %d]\n", y_1,x_1,y_2,x_2,h_1,w_1,h_2,w_2);
                        continue;
                    }
                    if(y_2+h_2>=N+1 || x_2+w_2>=M+1)
                    {
                      //  printf("2 :[y_1 :%d][x_1 :%d][y_2 :%d][x_2 :%d]\n[h_1 : %d][w_1 : %d][h_2 : %d][w_2 : %d]\n", y_1,x_1,y_2,x_2,h_1,w_1,h_2,w_2);
                        continue;
                    }
                    if(!((y_1 + h_1 < y_2 + 1) || \
                       (x_1 + w_1 < x_2 + 1) || \
                       (y_2 + h_2 < y_1 + 1) || \
                       (x_2 + w_2 < x_1 + 1)))
                    {
                      continue;
                    }

                    //rectangle 1 sum
                    for(int i=0; i<h_1; i++)
                    {
                        for(int j=0; j<w_1; j++)
                        {
                            sum += map[y_1 + i][x_1 + j];
                        }
                    }

                    //rectangle 2 sum
                    for(int i=0; i<h_2; i++)
                    {
                        for(int j=0; j<w_2; j++)
                        {
                            sum += map[y_2 + i][x_2 + j];
                        }
                    }

                    if (maxx < sum)
                    {
                        maxx = sum;
                    }
                }
            }
        }
    }

    return maxx;
}

int main() {
    scanf("%d %d", &N, &M);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for(int h_1 = 1; h_1 <= N; h_1++)
    {
        for(int w_1 = 1; w_1<=M ; w_1++)
        {
            for(int h_2=1; h_2<=N ; h_2++)
            {
                for(int w_2=1; w_2<=M ; w_2++)
                {
                  int ret = 0;
                  ret = solve(h_1,w_1,h_2,w_2);
                  ans = max(ans, ret);
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}