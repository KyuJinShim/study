#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int bomb[101];
int tmp[101];
int erased[101];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0;i < N;i++)
        scanf("%d", &bomb[i]);


    int start_idx = 0;
    int length = N;
    int exploded = 0;
    while (1)
    {
        exploded = 0;
        memset(erased, 0, sizeof(erased));
        memset(tmp, 0, sizeof(tmp));

        // check same bomb
        int i = 0;
        int cnt = 1;
        while (i < length)
        {
            if ((bomb[i] == bomb[i + 1]) && (i < length - 1))
            {
                cnt++;
            }
            else
            {
                // mark zeror
                if (cnt >= M)
                {
                    for (int j = 0;j < cnt;j++)
                    {
                        erased[i - j] = -1;
                    }
                    exploded = 1;
                }
                cnt = 1;
            }
            i++; // check next bomb
        }

        if (exploded == 0) break; // escape 

        // delete same bob
        int newbomb_length = 0;
        for (int i = 0;i < length;i++)
        {
            if (erased[i] != -1)
            {
                tmp[newbomb_length++] = bomb[i];
            }
        }
        memset(bomb, 0, sizeof(bomb));
        for (int i = 0;i < newbomb_length;i++)
        {
            bomb[i] = tmp[i];
        }
        length = newbomb_length;
    }

    printf("%d\n", length);
    for (int i = 0;i < length;i++)
    {
        printf("%d\n", bomb[i]);
    }

    return 0;
}