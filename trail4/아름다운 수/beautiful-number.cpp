#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int ans = 0;
int N;

void solve(int depth)
{
    if(N == depth)
    {
        //check 1,2,3,4 
        for(int start = 0 ;start<v.size();)
        {
            int check_num = v[start];
            int end = start;
            
            while(end+1<v.size() && v[end] == v[end+1])
            {
                end++;
            }

            if((end - start + 1) % check_num)
            {
                return;
            }

            if(end > start)
            {
                start = end;
            }
            start++;
        }
        ans++;
        return;
    }

    for(int i=1;i<=4;i++)
    {
        v.push_back(i);
        solve(depth+1);
        v.pop_back();
    }
}

int main() {
    cin >> N;
    
    solve(0);

    cout << ans << endl;

    return 0;
}