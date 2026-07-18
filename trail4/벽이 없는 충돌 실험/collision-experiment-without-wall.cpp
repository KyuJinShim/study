#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
struct ball {
    int num;
    int x;
    int y;
    int w;
    char d;
};

struct Compare_pos {
    bool operator()(const ball& a, const ball& b)
    {
        if (a.y == b.y)
        {
            return a.x > b.x;
        }
        return a.y > b.y;
    }
};

struct Compare_power {
    bool operator()(const ball& a, const ball& b)
    {
        if (a.w == b.w)
        {
            return a.num > b.num;
        }
        return a.w > b.w;
    }
};

vector<ball> balls;

int dy[256];
int dx[256];
const int MAX_TIMEOUT = 4000;
int main() {

    dy['U'] = 1;dx['U'] = 0;
    dy['D'] = -1; dx['D'] = 0;
    dy['L'] = 0; dx['L'] = -1;
    dy['R'] = 0; dx['R'] = 1;

    cin >> T;

    for (int testcase = 0; testcase < T; testcase++)
    {
        balls.clear();

        cin >> N;
        //ball input
        for (int num = 1;num <= N;num++)
        {
            int x, y, w;
            char d;
            cin >> x >> y >> w >> d;
            y *= 2;
            x *= 2;
            balls.push_back({ num, x, y, w, d });
        }

        int time = 0;
        int last_crushed_time = 0;
        while (time < MAX_TIMEOUT)
        {
            time++;

            //move balls
            vector<ball> tmp;
            for (int idx = 0;idx < balls.size(); idx++)
            {
                ball cur = balls[idx];
                int ny = cur.y + dy[cur.d];
                int nx = cur.x + dx[cur.d];

                if (nx < -2000 || nx > 2000 ||
                    ny < -2000 || ny > 2000)
                    continue;

                tmp.push_back({ cur.num, nx, ny,cur.w, cur.d });
            }

            //sort tmp
            sort(tmp.begin(), tmp.end(), Compare_pos());

            // move balls
            balls.clear();
            for (int start = 0; start < tmp.size();)
            {
                int end = start;
                int winner = start;

                while (end + 1 < tmp.size() &&
                    tmp[end].y == tmp[end + 1].y &&
                    tmp[end].x == tmp[end + 1].x)
                {
                    end++;

                    if ((tmp[winner].w < tmp[end].w) ||
                        (tmp[winner].w == tmp[end].w) && (tmp[winner].num < tmp[end].num))
                    {
                        winner = end;
                    }
                }

                balls.push_back(tmp[winner] );

                if (end != start)
                {
                    last_crushed_time = time;
                }
                start = end + 1;
            }
        }
        if (last_crushed_time == 0)
            cout << "-1" << endl;
        else
            cout << last_crushed_time << endl;
    }

    return 0;
}
