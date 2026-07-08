#include <iostream>
#include <vector>

using namespace std;

int N, M, T;
int map[101][101];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int count[101][101] = {0,};

void copy_count(int dst[][101], int src[][101])
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

int solve()
{
    for(int t=0;t<T;t++)
    {
        int next_count[101][101] = {0,};

        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(count[i][j])
                {
                    int maxx = -1e9;
                    int ny = 0;
                    int nx = 0;
                    for(int dir=0;dir<4;dir++)
                    {
                        int checky = i + dy[dir];
                        int checkx = j + dx[dir];
                        if(maxx < map[checky][checkx])
                        {
                            ny = checky;
                            nx = checkx;
                            maxx = map[checky][checkx];
                        }
                    }

                    next_count[ny][nx]++;
                }
            }
        }

        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(next_count[i][j] > 1)
                {
                    next_count[i][j] = 0;
                }
            }
        }
        copy_count(count,next_count);
    }

    int ret = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(count[i][j])
            {
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    scanf("%d %d %d", &N, &M, &T);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    int r, c;
    for(int i=0;i<M;i++)
    {
        cin >> r >> c;
        count[r][c] = 1;
    }

    int ret = solve();

    cout << ret << endl;

    return 0;
}
