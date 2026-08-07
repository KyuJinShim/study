#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

char map[21][21];
int N;

int start_y, start_x;
int end_y, end_x;
int ans = 1e9;

struct pos{
    int y;
    int x;
    int step;
};

vector<int> v;

int dist[21][21] = {0,};

struct Coin{
    int y;
    int x;
    int num;
};

struct Compare{
    bool operator()(const Coin &a, const Coin &b)
    {
        return a.num < b.num;
    }
};

vector<Coin> coin;
vector<int> selected;
int SIZE;

void bfs(int sy, int sx)
{
    queue<pos> q;

    bool visited[21][21] = {0,};

    visited[sy][sx] = true;
    q.push({sy,sx,0});
    while(!q.empty())
    {
        pos cur = q.front();
        q.pop();

        dist[cur.y][cur.x] = cur.step;

        for(int dir=0;dir<4;dir++)
        {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
 
            if(!visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({ny,nx,cur.step+1});
            }
        }
    }   
}

void solve(int depth)
{
    if(depth == SIZE)
    {
        int cnt = 0;
        for(int i=0;i<selected.size();i++)
        {
            if(selected[i] == 1)
            {
                cnt++;
            }
        }
        if(cnt < 3) return;

        int sum = 0;
        int cur_y = start_y;
        int cur_x = start_x;

        for(int i=0;i<selected.size();i++)
        {
            if(selected[i] == 1)
            {
                bfs(cur_y, cur_x);

                int y = coin[i].y;
                int x = coin[i].x;

                sum += dist[y][x];
                
                cur_y = y;
                cur_x = x; 
            }
        }

        bfs(cur_y,cur_x);
        sum += dist[end_y][end_x];
        ans = min(sum, ans);
        return;
    }
    for(int i=0;i<2;i++)
    {
        selected.push_back({i});
        solve(depth+1);
        selected.pop_back();
    }
}

int main() 
{
    scanf("%d", &N);

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> map[i][j];
            
            if(map[i][j] == 'S')
            {
                start_y = i;
                start_x = j;
                map[i][j] = '.';
            }
            if(map[i][j] == 'E')
            {
                end_y = i;
                end_x = j;
                map[i][j] = '.';
            }
            if(map[i][j] != '.')
            {
                int num = map[i][j] - '0';
                coin.push_back({i,j,num});
            }
        }
    }
    
    sort(coin.begin(), coin.end(), Compare());

    SIZE = coin.size();

    solve(0);

    if(ans == 1e9)
        printf("-1\n");
    else
        printf("%d\n",ans);

    return 0;
}