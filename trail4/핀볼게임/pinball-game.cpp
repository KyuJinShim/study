#include <iostream>
#include <algorithm>

using namespace std;

int map[101][101];
int N;

// 1 : '/'
// 2 : '\'

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int convert_dir(int cur_dir, int bar){
    int next_dir;

    if(bar == 1)
    {
      if(cur_dir == 0)
      {
         next_dir = 1;
      }   
      else if(cur_dir == 1)
      {
        next_dir = 0;
      }
      else if(cur_dir == 2)
      {
        next_dir = 3;
      }
      else if(cur_dir == 3)
      {
        next_dir = 2;
      }
    }
    else if(bar == 2)
    {
      if(cur_dir == 0)
      {
         next_dir = 3;
      }   
      else if(cur_dir == 1)
      {
        next_dir = 2;
      }
      else if(cur_dir == 2)
      {
        next_dir = 1;
      }
      else if(cur_dir == 3)
      {
        next_dir = 0;
      }
    }
    else
    {
        next_dir = cur_dir;
    }

    return next_dir;
}

int solve(int start_y, int start_x, int start_dir)
{
    int ret = 0;
    int cur_y = start_y;
    int cur_x = start_x;
    int cur_dir = start_dir;

    while(1)
    {
        int ny = cur_y + dy[cur_dir];
        int nx = cur_x + dx[cur_dir];

        //printf("ny : %d, nx : %d, cnt :%d\n", ny, nx, ret);
        ret++;

        if(ny < 1 || ny > N || nx < 1 || nx > N)
        {
            break;
        }

        cur_y = ny;
        cur_x = nx;
        cur_dir = convert_dir(cur_dir, map[ny][nx]);
    }
    return ret;
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

    // left <-> right
    int ans = -1e9;
    int res = 0; 
    
    for(int y=1;y<=N;y++)
    {
        res = solve(y,0,1);
        ans = max(res,ans);

        res = solve(y,N+1,3); 
        ans = max(res,ans); 
    }

    // up, down
    for(int x=1;x<=N;x++)
    {
       res = solve(0,x,2);
       ans = max(res,ans);

       res = solve(N+1,x,0); 
       ans = max(res,ans); 
    }

    cout << ans << endl;

    return 0;
}