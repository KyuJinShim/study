#include <iostream>
#include <vector>

using namespace std;

int A[11];
int N;
vector<int> sel;
int ans = 1e9;

void solve(int depth)
{
    if(depth == 2*N)
    {
        int size = sel.size();
        int sumA = 0;
        int sumB = 0;

        int cnt = 0;
        for(int i=0;i<size;i++)
        {
            if(sel[i] == 0)
                cnt++;
        }

        if(cnt != N) return;

        for(int i=0;i<size;i++)
        {
            if(sel[i] == 0)
            {
                sumA += A[i];
            }
            else
            {
                sumB += A[i];
            }
        }

        int diff = abs(sumA - sumB);
        ans = min(diff,ans);
        return;
    }

    for(int i=0;i<2;i++)
    {
        sel.push_back({i});
        solve(depth+1);
        sel.pop_back();
    }
}

int main() {
    cin >> N;

    for(int i=0;i<2*N;i++)
    {
        cin >> A[i];
    }

    solve(0);
    cout << ans << endl;

    return 0;
}