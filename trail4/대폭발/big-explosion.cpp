#include <iostream>
#include <vector>

using namespace std;

int map[101][101] = {0,};
int N;
int M;
int r,c;

struct bomb{
    int y;
    int x;
};

vector<bomb> v;
int visited[101][101] = {0,};

int main() {
    scanf("%d %d %d %d", &N, &M, &r, &c);
    
    v.push_back({r,c});
    visited[r][c] = 1;

    for(int m=1;m<=M;m++)
    {
        int dist = 1;
        for(int i=1;i<m;i++)
        {
            dist *= 2;
        }
        //printf("dist :%d\n", dist);

        int loop = v.size();
        for(int i=0;i<loop;i++)
        {
            if(v[i].y + dist <= N)
            {
                if(!visited[v[i].y + dist][v[i].x])
                {
                    v.push_back({v[i].y + dist, v[i].x});
                    visited[v[i].y + dist][v[i].x] = 1;
                }
            }
            if(v[i].y - dist >= 1)
            {
                if(!visited[v[i].y - dist][v[i].x])
                {
                    v.push_back({v[i].y - dist, v[i].x});
                    visited[v[i].y - dist][v[i].x] = 1;
                }
            }
            if(v[i].x + dist <= N)
            {
                if(!visited[v[i].y][v[i].x + dist])
                {
                    v.push_back({v[i].y, v[i].x + dist});
                    visited[v[i].y][v[i].x + dist] = 1;
                }
            }
            if(v[i].x - dist >= 1)
            {
                if(!visited[v[i].y][v[i].x - dist])
                {
                    v.push_back({v[i].y, v[i].x - dist});
                    visited[v[i].y][v[i].x - dist] = 1;
                }
            }
        }
    }

    // for(int i=0;i<v.size();i++)
    //    printf("#%d : %d,%d\n", i, v[i].y, v[i].x);

    printf("%d\n", v.size());

    return 0;
}