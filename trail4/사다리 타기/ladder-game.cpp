#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

struct ladder{
    int v1;
    int v2;
    int level;
};

struct Compare{
    bool operator()(const ladder &a, const ladder &b)
    {
        if(a.level == b.level)
            return a.v1 < b.v1;

        return a.level < b.level;
    }
};

vector<ladder> Ladder;
int origin[12];
int ans = 1e9;
int max_level = 0;
vector<int> sel;

void down(int arr[12])
{
    for(int n=1;n<=N;n++)
    {
        int cur_level = 1;
        int cur_pos = n;

        while(cur_level <= max_level)
        {
            for(int i=0;i<Ladder.size();i++)
            {
                if((cur_level == Ladder[i].level) && sel[i] == 1)
                {
                    if(cur_pos == Ladder[i].v1)
                    {
                        cur_pos++;
                    }
                    else if(cur_pos == Ladder[i].v2)
                    {
                        cur_pos--;
                    }
                }
            } //for(int i=0;i<Ladder.size();i++)
            cur_level++;
        } // while(cur_level < M)
        arr[cur_pos] = n;
    }//for(int n=1;n<=N;n++)
}

bool same_check(int a[12], int b[12]){
    for(int i=1;i<=N;i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

int same_cnt = 0;

void solve(int depth)
{
    // pick ladder
    if(depth == Ladder.size()){
        int check[12] = {0,};
        down(check);

        if(same_check(origin,check))
        {
            same_cnt++;
            int cnt = 0;
            for(int i=0;i<sel.size();i++)
            {
                if(sel[i] == 1)
                    cnt++;
            }
            //printf("same_cnt : %d, cnt : %d\nsel : ",same_cnt, cnt);
            //for(int i=0;i<sel.size();i++)printf("%d ",sel[i]);printf("\n");
            ans = min(ans, cnt);

        }
        return;
    }
    for(int i=0;i<2;i++){
        sel.push_back(i);
        solve(depth+1);
        sel.pop_back();
    }
}

int main() {
    cin >> N >> M;

    // input ladder
    for(int i=0;i<M;i++){
        ladder tmp;
        cin >> tmp.v1 >> tmp.level;
        max_level = max(max_level, tmp.level);
        Ladder.push_back({tmp.v1, tmp.v1+1, tmp.level});
    }

    sort(Ladder.begin(),Ladder.end(),Compare());
    
    for(int i=0;i<M;i++)
        sel.push_back({1});
    down(origin);
    sel.clear();
    
    solve(0);
    
    //printf("same_cnt : %d\n", same_cnt);
    if(ans == 1e9)
        printf("0\n");
    else
        printf("%d\n", ans);
    return 0;
}
