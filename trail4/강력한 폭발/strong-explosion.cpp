#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos{
    int y;
    int x;
};

vector<pos> bomb;
vector<int> v;

int N;
int ans;
int map[21][21];

void copy_map(int dst[][21], int src[][21])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

void explode(int tgt[][21], int y, int x, int type)
{
    if(type == 1)
    {
        if(y-2 >= 0)
            tgt[y-2][x] = 1;
        if(y-1 >= 0)
            tgt[y-1][x] = 1;
        tgt[y][x] = 1;
        if(y+1 < N)
            tgt[y+1][x] = 1;
        if(y+2 < N)
            tgt[y+2][x] = 1;
    }
    else if(type == 2)
    {
        if(y-1 >= 0)
            tgt[y-1][x] = 1;
        if(y+1 < N)
            tgt[y+1][x] = 1;
        tgt[y][x] = 1;
        if(x-1 >= 0)
            tgt[y][x-1] = 1;
        if(x+1 < N)
            tgt[y][x+1] = 1;
    }
    else if(type == 3)
    {
        if(y-1 >= 0 && x-1 >= 0)
            tgt[y-1][x-1] = 1;
        if(y-1 >= 0 && x+1 < N)
            tgt[y-1][x+1] = 1;
        tgt[y][x] = 1;
        if(y+1 < N && x-1 >= 0)
            tgt[y+1][x-1] = 1;
        if(y+1 < N && x+1 < N)
            tgt[y+1][x+1] = 1;
    }
}

int count_explode(int tgt[][21])
{
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(tgt[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void solve(int depth)
{
    if(depth == bomb.size())
    {
        int tmp[21][21] = {0, };
        copy_map(tmp,map);

        for(int i=0;i<bomb.size();i++)
        {
            int y = bomb[i].y;
            int x = bomb[i].x;

            explode(tmp, y, x, v[i]);
        }
        int cnt = count_explode(tmp);
        ans = max(cnt, ans);
        return;
    }

    for(int i=1;i<=3;i++)
    {
        v.push_back({i});
        solve(depth+1);
        v.pop_back();
    }
}

int main() {
    cin >> N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
            {
                bomb.push_back({i,j});
            }
        }
    }

    solve(0);
    
    cout << ans << endl;

    return 0;
}