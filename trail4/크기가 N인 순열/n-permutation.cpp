#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
bool visited[9] = {0,};

void solve(int depth)
{
    if(depth == N)
    {
        for(int i=0;i<v.size();i++)
            printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
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

    solve(0);

    return 0;
}