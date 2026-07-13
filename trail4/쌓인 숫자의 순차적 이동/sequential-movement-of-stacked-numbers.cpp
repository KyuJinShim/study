#include <iostream>
#include <vector>

using namespace std;

int N, M;
int num[401];

int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

vector<int> map[21][21];

struct Pos {
    int y;
    int x;
};

Pos num_pos[401];

void solve()
{
    for (int m = 0;m < M;m++)
    {
        int cy = num_pos[num[m]].y;
        int cx = num_pos[num[m]].x;
        int cidx;

        // get current numbers idx
        for (int idx = 0;idx < map[cy][cx].size();idx++)
        {
            if (map[cy][cx][idx] == num[m])
            {
                cidx = idx;
                break;
            }
        }

        int ny = 0;
        int nx = 0;
        int max_val = 0;

        // get max number
        bool moved = false;
        for (int dir = 0;dir < 8;dir++)
        {
            int checky = cy + dy[dir];
            int checkx = cx + dx[dir];

            if (checky < 1 || checky > N || checkx < 1 || checkx > N) continue;
            if(map[checky][checkx].size() == 0) continue;

            for (int idx = 0;idx < map[checky][checkx].size();idx++)
            {
                if (map[checky][checkx][idx] > max_val)
                {
                    max_val = map[checky][checkx][idx];
                    ny = checky;
                    nx = checkx;
                    moved = true;
                }
            }
        }

        if(cy == ny && cx == nx) continue;

        if(moved)
        {
            vector<int> tmp;
            for (int idx = cidx; idx < map[cy][cx].size();idx++)
            {
                tmp.push_back({ map[cy][cx][idx] });
                
                // move
                num_pos[map[cy][cx][idx]].y = ny;
                num_pos[map[cy][cx][idx]].x = nx;
                map[ny][nx].push_back({ map[cy][cx][idx] });
            }

            map[cy][cx].erase(map[cy][cx].begin() + cidx, map[cy][cx].end());
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            int val;
            scanf("%d", &val);
            map[i][j].push_back({ val });
            num_pos[val].y = i;
            num_pos[val].x = j;
        }
    }

    for (int i = 0;i < M;i++)
    {
        scanf("%d", &num[i]);
    }

    solve();

    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            if (map[i][j].size() == 0)
            {
                printf("None");
            }
            else
            {
                for (int idx = map[i][j].size()-1;idx >= 0;idx--)
                {
                    printf("%d ", map[i][j][idx]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
