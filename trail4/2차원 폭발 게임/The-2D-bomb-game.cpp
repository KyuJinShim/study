#include <iostream>
#include <vector>
using namespace std;

/*
  map 행 탐색
 -> 연속 폭탄 카운팅
 -> M>=카운트 이면 map에서 0 처리
 -> map 행으로 탐색하며 0이 아니면 vector에 넣기
 -> 새로운 map에 아래서부터 채우기
 -> 오른쪽 90도 회전
 -> 반복
 */

int N, M, K;
int map[101][101];
vector<int> v;

void rotate_90_right()
{
    int tmp[101][101] = { 0, };

    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            tmp[i][j] = map[N + 1 - j][i];
        }
    }

    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            map[i][j] = tmp[i][j];
        }
    }
}

bool process_row(int col)
{
    bool exploded = false;
    // set zero
    for (int start = 1; start <= N;)
    {
        while (start <= N && map[start][col] == 0)
        {
            start++;
        }

        if(start > N)
            break;

        int end = start;

        while (end + 1 <= N && map[end][col] == map[end + 1][col])
        {
            end++;
        }
        int len = end - start + 1;

        if (len >= M)
        {
            for (int y = start;y <= end;y++)
            {
                map[y][col] = 0;
                exploded = true;
            }
        }

        start = end + 1;
    }

    return exploded;
}

void apply_gravity()
{
    // loop cols
    for (int x = 1;x <= N;x++)
    {
        v.clear();

        //find non-zero bombs
        for (int y = N;y >= 1;y--)
        {
            if (map[y][x] != 0)
            {
                v.push_back(map[y][x]);
            }
        }

        // clear row
        for (int y = N;y >= 1;y--)
        {
            map[y][x] = 0;
        }

        // set new bombs
        int idx = N;
        for (int i = 0;i < v.size();i++)
        {
            map[idx--][x] = v[i];
        }
    }
}

int count_bomb()
{
    int ret = 0;
    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            if (map[i][j])
            {
                ret++;
            }
        }
    }
    return ret;
}

void print_map()
{
    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int ans = 0;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    bool exploded = true;


    for (int k = 1;k <= K;k++)
    {
        while(1)
        {
            exploded = false;
            for (int x = 1;x <= N;x++)
            {
                if (process_row(x))
                {
                    exploded = true;
                }
            }

            if(!exploded)
                break;

            apply_gravity();
        }
        
        rotate_90_right();
        apply_gravity();
    }

    while(true)
    {
        exploded = false;

        for(int x=1;x<=N;x++)
        {
            if(process_row(x))
                exploded = true;
        }

        if(!exploded)
            break;

        apply_gravity();
    }

    ans = count_bomb();
    printf("%d\n", ans);

    return 0;
}