#include <iostream>
#include <vector> 
#include <cstring>

using namespace std;

int T;
int N, M;

struct ball {
    int y;
    int x;
    char d;
};

int dy[256];
int dx[256];

vector<ball> balls;
vector<ball> new_balls;

void set_dir(int* y, int* x, char* dir)
{
    if (*y < 1)
    {
        *y = 1;
        *dir = 'D';
    }
    else if (*y > N)
    {
        *y = N;
        *dir = 'U';
    }
    else if (*x < 1)
    {
        *x = 1;
        *dir = 'R';
    }
    else if (*x > N)
    {
        *x = N;
        *dir = 'L';
    }
}

int main() {
    cin >> T;

    dy['U'] = -1;dx['U'] = 0;
    dy['D'] = 1;dx['D'] = 0;
    dy['L'] = 0;dx['L'] = -1;
    dy['R'] = 0;dx['R'] = 1;

    for (int t = 0;t < T;t++)
    {
        // get N, M
        cin >> N >> M;

        // initialize
        int y, x;
        char d;
        balls.clear();

        // get balls' information
        for (int m = 0;m < M;m++)
        {
            cin >> y >> x >> d;
            balls.push_back({ y,x,d });
        }

        // simulate
        for (int time = 0;time < 2*N;time++)
        {
            new_balls.clear();
            int visited[51][51];
            memset(visited, 0, sizeof(visited));

            for (int i = 0;i < balls.size();i++)
            {
                // current position
                int cy = balls[i].y;
                int cx = balls[i].x;
                char cd = balls[i].d;

                // next position
                int ny = cy + dy[cd];
                int nx = cx + dx[cd];
                char nd = cd;

                // out of board
                set_dir(&ny, &nx, &nd);

                visited[ny][nx]++;
                new_balls.push_back({ ny,nx,nd });
            }

            // erase
            balls.clear();
            for (int b = 0;b < new_balls.size();b++)
            {
                int y = new_balls[b].y;
                int x = new_balls[b].x;
                if (visited[y][x] > 1)
                {
                    continue;
                }
                else
                {
                    balls.push_back({y,x,new_balls[b].d});
                }
            }
            //erase-end
        }// simulate-end

        cout << balls.size() << endl;
    }

    return 0;
}
