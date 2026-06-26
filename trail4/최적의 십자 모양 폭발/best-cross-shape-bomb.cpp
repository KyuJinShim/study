#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ans = -1e9;
int map[51][51];
int tmp[51][51];

vector<int> v;

void print_map()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }
}

int check_pair(int dest[][51])
{
    int cnt = 0;
    // horizontal check
    for(int y=1;y<=N;y++)
    {
        for(int x=1;x<=N-1;x++)
        {
           if(dest[y][x] == dest[y][x+1] && dest[y][x] != 0)
           {
              cnt++;
           }
        }
    }

    // vertical check
    for(int x=1;x<=N;x++)
    {
        for(int y=1;y<=N;y++)
        {
          if(dest[y][x] == dest[y+1][x] && dest[y][x] != 0)
           {
              cnt++;
           }
        }
    }
    return cnt;
}

void copy_map(int dest[][51], int src[][51])
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}

void bomb(int ty, int tx, int dest[][51])
{
  int power = tmp[ty][tx] - 1;
  
  tmp[ty][tx] = 0;
  for(int p=1;p<=power;p++)
  {
    if(ty+p <= N) tmp[ty+p][tx] = 0;
    if(tx+p <= N) tmp[ty][tx+p] = 0;
    if(ty-p >= 1) tmp[ty-p][tx] = 0;
    if(tx-p >= 1) tmp[ty][tx-p] = 0;
  }
}

void gravity()
{
    for(int x=1;x<=N;x++)
    {
        v.clear();
        for(int y=N;y>=1;y--)
        {
            if(tmp[y][x] != 0)
            {
                v.push_back(tmp[y][x]);
            }
        }

        if(v.size() > 0)
        {
            for(int y=N;y>=1;y--)
            {
                tmp[y][x] = 0;
            }
            int idx = N;
            for(int i=0;i<v.size();i++)
            {
                tmp[idx--][x] = v[i];
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
          memset(tmp, 0 , sizeof(tmp));
          copy_map(tmp,map);
          bomb(i,j,tmp);
          gravity();
          int ret = check_pair(tmp);
          ans = max(ret,ans);
        }
    }

    printf("%d\n", ans);

    return 0;
}
