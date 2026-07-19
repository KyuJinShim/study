#include <iostream>
#include <vector> 

using namespace std;

int K, N;

vector<int> v;
vector<int> ans;

void solve(int depth){
    if(depth == N)
    {
        for(int i=0;i<ans.size();i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0;i<v.size();i++)
    {
        ans.push_back(v[i]);
        solve(depth+1);
        ans.pop_back();
    }
}

int main() {
    cin >> K >> N;

    for(int i=1;i<=K;i++)
    {
        v.push_back({i});
    }

    solve(0);

    return 0;
}