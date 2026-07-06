#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, M, K;

struct Pos {
    int y;
    int x;
};

struct Cmd {
    char d;
    int p;
};

int dy[256];
int dx[256];

deque<Pos> snake;
vector<Cmd> cmd;

bool body[101][101];
bool apple[101][101];

int main() {
    cin >> N >> M >> K;

    for (int i = 0;i < M;i++)
    {
        int x, y;
        cin >> y >> x;
        apple[y][x] = true;
    }

    for (int i = 0;i < K;i++)
    {
        Cmd c;
        cin >> c.d >> c.p;
        cmd.push_back(c);
    }

    dy['U'] = -1;dx['U'] = 0;
    dy['D'] = 1;dx['D'] = 0;
    dy['L'] = 0;dx['L'] = -1;
    dy['R'] = 0;dx['R'] = 1;

    body[1][1] = true;
    snake.push_back({ 1,1 });
    int ans = 0;

    for (int i = 0;i < cmd.size();i++)
    {
        for (int j = 0;j < cmd[i].p;j++)
        {
            int ny = snake.front().y + dy[cmd[i].d];
            int nx = snake.front().x + dx[cmd[i].d];

            ans++;

            if (ny < 1 || ny > N || nx < 1 || nx > N)
            {
                cout << ans << endl;
                return 0;
            }

            bool eat = apple[ny][nx];
            apple[ny][nx] = false;

            if (!eat)
            {
                int taily = snake.back().y;
                int tailx = snake.back().x;
                body[taily][tailx] = false;
                snake.pop_back();
            }

            if (body[ny][nx])
            {
                cout << ans << endl;
                return 0;
            }

            snake.push_front({ ny,nx });
            body[ny][nx] = true;
        }
    }

    cout << ans << endl;

    return 0;
}