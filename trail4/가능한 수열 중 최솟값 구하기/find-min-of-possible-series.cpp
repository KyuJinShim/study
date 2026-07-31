#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> ans;

bool possible(int n){
    v.push_back({n});

    int start = v.size()-1;

    for(int len=1;len<=v.size()/2;len++)
    {
        int start2 = start - len;
        int cnt = 0;

        for(int i=0;i<len;i++)
        {
            if(v[start-i] == v[start2-i])
            {
                cnt++;
            }
        }
        if(cnt == len)
        {
            v.pop_back();
            return false;
        }
    }

    v.pop_back();
    return true;
}

bool DONE = false;

void solve(int depth){
    if(DONE)
        return;
    if(depth == N)
    {
        if(!DONE)
        {
            for(int i=0;i<v.size();i++)
            {
                ans.push_back({v[i]});
                DONE = true;
            }
        }
        return;
    }
    for(int i=4;i<=6;i++)
    {
        if(possible(i))
        {
            v.push_back({i});
            solve(depth+1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> N;

    solve(0);

    for(int i=0;i<ans.size();i++)
    {
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
