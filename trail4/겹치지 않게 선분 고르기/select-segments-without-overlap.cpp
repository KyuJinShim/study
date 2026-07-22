#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line{
    int start;
    int end;
};

vector<line> Line;
vector<int> sel;
int N;
int ans = 0;

bool possible(int idx)
{
    for(int i=0;i<sel.size();i++)
    {
        line a = Line[idx];
        line b = Line[sel[i]];

        if(!((a.end < b.start) || (a.start > b.end)))
            return false;
    }
    return true;
}

void solve(int idx)
{
    if(idx == N)
    {
        int size = sel.size();
        ans = max(ans, size);
        return;
    }    

    if(possible(idx))
    {
        sel.push_back({idx});
        solve(idx+1);
        sel.pop_back();
    }

    solve(idx+1);
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++)
    {
        line cur;
        cin >> cur.start >> cur.end;
        Line.push_back({cur});
    }

    solve(0);

    cout << ans << endl;

    return 0;
}