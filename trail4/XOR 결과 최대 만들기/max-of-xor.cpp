#include <iostream>
#include <vector>

using namespace std;
int N,M;
int num[21];
vector<int> v;
int ans = 0;
void solve(int depth, int start)
{
  if(depth == M)
  {
    int tmp = 0;
    for(int i=0;i<v.size();i++)
    {
        tmp ^= v[i];
    }
    ans = max(tmp,ans);
    return;
  } 
  for(int i=start;i<N;i++)
  {
    v.push_back(num[i]);
    solve(depth+1, i+1);
    v.pop_back();
  }  
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        scanf("%d", &num[i]);
    }

    solve(0,0);

    printf("%d\n", ans);

    return 0;
}