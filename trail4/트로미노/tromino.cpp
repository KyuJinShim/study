#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;
int map[200][200];

int main() {
    scanf("%d %d", &N, &M);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            // block 1 - all 4 cases
            if((i+1) < N && (j+1) <M)
            {
              ans = max(ans, (map[i][j] + map[i+1][j] + map[i+1][j+1]));

              ans = max(ans, (map[i][j] + map[i+1][j] + map[i][j+1]));

              ans = max(ans, (map[i][j] + map[i][j+1] + map[i+1][j+1]));

              ans = max(ans, (map[i+1][j] + map[i][j+1] + map[i+1][j+1]));
            }

            // block 2 - vertical
            if((i+2) < N)
            {
               ans = max(ans, (map[i][j] + map[i+1][j] + map[i+2][j]));
            }

            // block 2 - horizontal
            if((j+2) < M)
            {
                ans = max(ans, (map[i][j] + map[i][j+1] + map[i][j+2]));
            }
        }
    }

    printf("%d", ans);

    return 0;
}