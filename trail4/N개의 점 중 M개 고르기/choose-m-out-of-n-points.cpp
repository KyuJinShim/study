#include <iostream>
#include <vector>

using namespace std;

int N,M;
int ans = 1e9;

struct point{
    int y;
    int x;
};

vector<point> Point;
vector<int> sel;

void solve(int depth)
{
    if(sel.size() == M)
    {
        int max_dist = 0;
        for(int i=0;i<sel.size();i++)
        {
            for(int j=i+1;j<sel.size();j++)
            {
                if(i==j) continue;

                int dx = Point[sel[i]].x - Point[sel[j]].x;
                int dy = Point[sel[i]].y - Point[sel[j]].y;

                dx *= dx;
                dy *= dy;

                max_dist = max(dx+dy, max_dist);
            }
        }

        ans = min(ans, max_dist);
        return;
    }

    if(depth == N) return;

    //depth selected
    sel.push_back(depth);
    solve(depth+1);
    sel.pop_back();

    //depth not selected
    solve(depth+1);
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        point tmp;
        cin >> tmp.x >> tmp.y;
        Point.push_back({tmp});
    }

    solve(0);

    cout << ans << endl;

    return 0;
}
