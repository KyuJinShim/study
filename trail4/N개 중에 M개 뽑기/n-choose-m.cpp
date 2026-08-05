#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void solve(int depth, int start)
{
    if(depth == M)
    {
        for(int i=0;i<v.size();i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
        return;
    }
    for(int i=start;i<=N;i++)
    {
        v.push_back({i});
        solve(depth+1, i+1);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;

    solve(0,1);

    return 0;
}
