#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ball{
    int num;
    int y;
    int x;
    char d;
    int v;
};

struct Compare{
    bool operator()(const ball & a, const ball & b)
    {
        if(a.v == b.v)
            return a.num > b.num;

        return a.v > b.v;
    }
};

vector<ball> balls;

int N,M,T,K;
int dy[256];
int dx[256];

void solve()
{
    for(int t=0;t<T;t++)
    {
        vector<ball> visited[51][51];
        // loop balls
        for(int idx=0;idx<balls.size();idx++)
        {
            int cnum = balls[idx].num;
            int cy = balls[idx].y;
            int cx = balls[idx].x;
            char cd = balls[idx].d;
            int cv = balls[idx].v;

            // move balls
            int ny  = cy;
            int nx = cx;
            char nd = cd;
            for(int i=0;i<cv;i++)
            {
                ny += dy[nd];
                nx += dx[nd];
                if(ny < 1)
                {
                    ny = 2;
                    nd = 'D';
                }
                if(ny > N)
                {
                    ny = N-1;
                    nd = 'U';
                }
                if(nx < 1)
                {
                    nx = 2;
                    nd = 'R';
                }
                if(nx > N)
                {
                    nx = N-1;
                    nd = 'L';
                }
            } // for(int i=0;i<cv;i++)
            visited[ny][nx].push_back({cnum,ny,nx,nd,cv});
        }// for(int idx=0;idx<balls.size();idx++)
        balls.clear();
        for(int checky = 1; checky <= N ; checky++)
        {
            for(int checkx =1; checkx <= N; checkx++)
            {
                if(visited[checky][checkx].size() == 0) continue;

                if(visited[checky][checkx].size() > K)
                {
                    sort(visited[checky][checkx].begin(),visited[checky][checkx].end(),Compare());
                    visited[checky][checkx].erase(visited[checky][checkx].begin()+K, visited[checky][checkx].end());
                }

                if(visited[checky][checkx].size() > 0)
                {
                    for(int idx=0;idx<visited[checky][checkx].size();idx++)
                    {
                        balls.push_back(visited[checky][checkx][idx]);
                    }
                }
            }
        }
    }//for(int t=0;t<T;t++)
}

int main() {
    cin >> N >> M >> T >> K;

    for(int i=1;i<=M;i++)
    {
        int y,x,v;
        char d;
        cin >> y >> x >> d >> v;
        balls.push_back({i,y,x,d,v});
    }

    dy['U'] = -1;dx['U'] = 0;
    dy['D'] = 1;dx['D'] = 0;
    dy['L'] = 0;dx['L'] = -1;
    dy['R'] = 0;dx['R'] = 1;

    solve();

    cout << balls.size() << endl;

    return 0;
}
