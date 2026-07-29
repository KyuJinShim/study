#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char input_str[201];
vector<int> v;
int element[4] = {1,2,3,4};
int NUM_CNT = 0;
int ans = -1e9;
int alpha[256] = {0,};

void solve(int depth){
    if(depth == NUM_CNT)
    {
        int num_idx = 0;
        int sum = v[num_idx++];
        for(int i=1;i<strlen(input_str);i+=2){
            if(input_str[i] == '+')
            {
                sum += v[num_idx++];
            }
            else if(input_str[i] == '-')
            {
                sum -= v[num_idx++];
            }
            else if(input_str[i] == '*')
            {
                sum *= v[num_idx++];
            }
        }
        ans = max(ans, sum);
        return;
    }
 
    char ch = input_str[depth*2];
    if(alpha[ch] == 0)
    {
        for(int i=0;i<4;i++)
        { 
            v.push_back({element[i]});
            alpha[ch] = element[i];
            solve(depth+1);
            v.pop_back();
            alpha[ch] = 0;
        }
    }
    else
    {
        v.push_back({alpha[ch]});
        solve(depth+1);
        v.pop_back();
    }
}

int main() {
    scanf("%s", input_str);
    NUM_CNT = (strlen(input_str) / 2) + 1;
    
    //printf("NUM_CNT  : %d\n", NUM_CNT);
   
    solve(0);

    printf("%d\n", ans);

    return 0;
}