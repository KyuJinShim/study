#include <iostream>
#include <vector>

using namespace std;

int K, N;

vector<int> v;

bool possible(int num){
    if(v.size() < 2)
        return true;

    int size = v.size();    
    if(v[size-1] == num && v[size-2] == num)
        return false;
    
    return true;
}

void solve(int depth){
    if(depth == N)
    {
        for(int i=0;i<v.size();i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=K;i++)
    {
        if(possible(i))
        {
            v.push_back(i);
            solve(depth+1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> K >> N;

    solve(0);    

    return 0;
}
