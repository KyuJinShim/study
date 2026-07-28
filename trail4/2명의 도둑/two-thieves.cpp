#include <iostream>
#include <vector>

using namespace std;

int N,M,C;

int map[11][11];

struct pos{
    int y;
    int x;
};

vector<pos> sel;
vector<int> sel_weight;
bool visited[11][11] = {0,};

int ans = 0;
int check_sum = 0;
int profit[11][11] = {0,};

void set_profit(int y, int x, int depth){
    if(depth == M)
    {
        int size = sel_weight.size();
        int sum = 0;
        int tmp = 0;
        
        check_sum = 0;
        for(int i=0;i<size;i++)
        {
            if(sel_weight[i] == 1)
            {
                sum += map[y][x+i];
                int tmp = map[y][x+i] * map[y][x+i];
                check_sum += tmp;
            }
        }

        if(sum > C) 
            return;

        profit[y][x] = max(profit[y][x], check_sum);
        return;
    }

    for(int i=0;i<2;i++)
    {
        sel_weight.push_back({i});
        set_profit(y,x,depth+1);
        sel_weight.pop_back();
    }
}

bool possible(int y,int x)
{
    if(sel.empty())
        return true;

    int y1 = sel[0].y;
    int x1 = sel[0].x;

    if(y != y1)
        return true;

    return (x1 + M <= x || x + M <= x1);
}

void solve(int depth){

    if(depth == 2){
        int a = profit[sel[0].y][sel[0].x];
        int b = profit[sel[1].y][sel[1].x];

        ans = max(a+b, ans);
        return;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=N-M;j++)
        {
            if(possible(i,j))
            {
                sel.push_back({i,j});
                solve(depth+1);
                sel.pop_back();
            }
        }
    }
}

int main() {
    cin >> N >> M >> C;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=N-M;j++)
        {
            set_profit(i,j,0);
        }
    }

    solve(0);

    printf("%d\n", ans);

    return 0;
}