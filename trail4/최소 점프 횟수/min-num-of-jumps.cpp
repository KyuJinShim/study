#include <iostream>

using namespace std;

int N;
int num[11];
int ans = 1e9;
bool visited[11] = {0,};

bool solve(int depth, int pos){
    
    if(pos == N)
    {
       // printf("[reached N]");
       // printf("[ans : %d depth :%d]\n", ans, depth);
        ans = min(ans, depth);
        return true;
    }

    int avail_jump = num[pos];
    // printf("depth:%d, pos : %d, avail : %d\n", depth, pos, num[pos]);
    for(int i=1;i<=avail_jump;i++)
    {
        if(pos + i <= N)
        {
            solve(depth+1, pos+i);
        }
    }
    return false;
}

int main() {
    cin >> N;

    for(int i=1;i<=N;i++)
    {
        cin >> num[i];
    }

    solve(0,1);
    if(ans != 1e9)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}
