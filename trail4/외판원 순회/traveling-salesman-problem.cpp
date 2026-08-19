#include <iostream>
#include <vector>

using namespace std;

int N;
int A[11][11];
bool visited[11] = {0,};
vector<int> v;
int ans = 1e9;

bool possible(int pos)
{
    if(v.size() == 0)
    {
        if(A[1][pos] != 0)
            return true;
        else
            return false;
    }
    else
    {
        if(A[v.back()][pos] != 0)
            return true;
        else
            return false;
    }
}

void solve(int depth)
{
    if(depth == N-1)
    {
        if(A[v.back()][1] == 0)
            return;

        int sum = A[1][v[0]];
        for(int idx=0;idx<v.size()-1;idx++)
        {
            sum += A[v[idx]][v[idx+1]];
            if(sum > ans)
                return;
        }
        sum += A[v.back()][1];
        
        ans = min(ans,sum);
        return;
    }
    for(int i=2;i<=N;i++)
    {
        if(!visited[i] && possible(i))
        {
            visited[i] = true;
            v.push_back({i});
            solve(depth+1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    solve(0);

    cout << ans << endl;
    
    return 0;
}
