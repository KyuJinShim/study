#include <iostream>
#include <cstring>

using namespace std;

int N;
int blocks[101];
int idx;
int blocks_len;
int s[3];
int e[3];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) 
    {
        scanf("%d", &blocks[i]);
    }
    scanf("%d %d",&s[1], &e[1]);
    scanf("%d %d",&s[2], &e[2]);
    
    blocks_len = N;
    for(int t=1;t<=2;t++)
    {
        int new_blocks[101] = {0,};
        idx = 0;

        // up
        for(int i=1;i<=s[t]-1;i++)
        {
            new_blocks[++idx] = blocks[i];
        }

        // down
        for(int i=e[t]+1;i<=blocks_len;i++)
        {
            new_blocks[++idx] = blocks[i];
        }

        memset(blocks,0,sizeof(blocks));
        for(int i=1;i<=idx;i++)
        {
            blocks[i] = new_blocks[i];
        }
        blocks_len = idx;
    }    

    printf("%d\n",blocks_len);
    for(int i=1;i<=idx;i++)
    {
        printf("%d\n", blocks[i]);
    }

    return 0;
}
