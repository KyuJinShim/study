#include <iostream>
#include <vector>

using namespace std;

int N;
int map[10][10];
bool visited[10] = {0,};
vector<int> col;
int ans = 0;

void solve(int depth)
{
    if(depth == N)
    {
        int sum = 0;
        for(int i=0;i<col.size();i++)
        {
            sum += map[i+1][col[i]];
        }
        ans = max(ans, sum);
        return;
    }
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            col.push_back({i});
            solve(depth + 1);
            visited[i] = false;
            col.pop_back();
        }
    }
}

int main() {
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> map[i][j];
        }
    }    

    solve(0);
    cout << ans << endl;

    return 0;
}