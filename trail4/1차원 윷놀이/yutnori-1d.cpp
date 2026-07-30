#include <iostream>
#include <vector>

using namespace std;

int M;
int K;
int N;

vector<int> v;
int pos[5];
int turn[13];
int ans = -1e9;

void solve(int depth)
{
    if(depth == N)
    {
        for(int i=1;i<=K;i++)
        {
            pos[i] = 1;
        }

        int score = 0;
        for(int i=0;i<v.size();i++)
        {
            int selected = v[i];
            
            if(pos[selected] >= M) 
                continue;
            
            pos[selected] += turn[i];
            
            if(pos[selected] >= M) 
                score++;
        }
        ans = max(ans,score);
        return;
    }

    for(int i=1;i<=K;i++)
    {
        v.push_back({i});
        solve(depth+1);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        scanf("%d", &turn[i]);
    }

    solve(0);

    printf("%d\n", ans);

    return 0;
}