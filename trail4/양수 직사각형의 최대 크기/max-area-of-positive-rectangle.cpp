#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;
int map[20][20];

int solve(int h,int w)
{
    int ret = -1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(i+h >= N+1 || j+w >= M+1)
              continue;

            bool flag = true;
            for(int y=0;y<h;y++)
            {
                for(int x=0;x<w;x++)
                {
                    if(map[i+y][j+x] <= 0)
                    {
                        flag = false;
                    }
                }
            }
            if(flag)
            {
                ret = max(ret, h*w);
            }
        }
    }
    return ret;
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

    int ans = -2;
    for(int h=1;h<=N;h++)
    {
        for(int w=1;w<=M;w++)
        {
           int ret = solve(h,w);
           if(ret != -1)
           {
              ans = max(ans, ret);
           }
        }
    }

    if(ans == -2)
        printf("%d", -1);
    else
        printf("%d",ans);

    return 0;
}