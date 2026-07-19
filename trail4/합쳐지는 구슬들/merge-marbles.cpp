#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; //map size
int M; //balls
int T; //Time

struct ball {
    int num;
    int y;
    int x;
    char d;
    int w;
};

struct ComparePos {
    bool operator()(const ball& a, const ball& b)
    {
        if (a.y == b.y)
        {
            return a.x > b.x;
        }
        return a.y > b.y;
    }
};

struct CompareWeight {
    bool operator()(const ball& a, const ball& b)
    {
        return a.w > b.w;
    }
};

int dy[256];
int dx[256];

vector<ball> balls;

void border_check(int* ny, int* nx, char* nd)
{
    if (*ny < 1)
    {
        *ny = 1;
        *nd = 'D';
    }
    else if (*ny > N)
    {
        *ny = N;
        *nd = 'U';
    }
    else if (*nx < 1)
    {
        *nx = 1;
        *nd = 'R';
    }
    else if (*nx > N)
    {
        *nx = N;
        *nd = 'L';
    }
}

void solve() {
    for (int time = 1; time <= T; time++)
    {
        vector<ball> tmp;

        // move balls
        for (int idx = 0;idx < balls.size();idx++)
        {
            ball cur = balls[idx];
            int ny = cur.y + dy[cur.d];
            int nx = cur.x + dx[cur.d];
            char nd = cur.d;

            border_check(&ny, &nx, &nd);

            tmp.push_back({ cur.num,ny,nx,nd,cur.w });
        }

        //same pos check
        sort(tmp.begin(), tmp.end(), ComparePos());

        balls.clear();
        for (int start = 0;start < tmp.size();)
        {
            int end = start;
            int winner_idx = start;
            int winner_num = tmp[start].num;
            char winner_d = tmp[start].d;
            int total_w = tmp[start].w;

            while (end + 1 < tmp.size() &&
                tmp[end].y == tmp[end + 1].y &&
                tmp[end].x == tmp[end + 1].x)
            {
                end++;

                // 1. add all w
                total_w += tmp[end].w;

                // 2. d is follows max num
                if (tmp[winner_idx].num < tmp[end].num)
                {
                    winner_idx = end;
                    winner_num = tmp[end].num;
                    winner_d = tmp[end].d;
                }
            }

            balls.push_back({ winner_num, tmp[end].y, tmp[end].x, winner_d, total_w });
            if (start < end)
            {
                start = end;
            }
            start++;
        }
    }
}

int main() {
    cin >> N >> M >> T;

    for (int num = 1; num <= M; num++)
    {
        int r, c, w;
        char d;
        cin >> r >> c >> d >> w;
        balls.push_back({ num,r,c,d,w });
    }

    dy['U'] = -1; dx['U'] = 0;
    dy['D'] = 1; dx['D'] = 0;
    dy['L'] = 0; dx['L'] = -1;
    dy['R'] = 0; dx['R'] = 1;

    solve();

    sort(balls.begin(), balls.end(), CompareWeight());

    printf("%d %d\n", balls.size(), balls[0].w);

    return 0;
}