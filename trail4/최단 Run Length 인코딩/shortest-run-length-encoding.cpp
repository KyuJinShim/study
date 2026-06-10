#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

char A[11];
int LENGTH_A;
int ans = INT_MAX;

void shift(char dest[11], char src[11])
{
    for(int i=1;i<LENGTH_A;i++)
    {
        dest[i] = src[i-1];
    }
    dest[0] = src[LENGTH_A-1];

/*
    for(int i=0;i<LENGTH_A;i++)
        printf("%c",dest[i]);
    printf("\n");
*/
}

int RunLengthEncode(char X[11])
{
    int cur_pos = 0;
    char encoded_buff[11] = "";

    while(cur_pos < LENGTH_A)
    {
        char ch = X[cur_pos];
        int count = 1;
        for(int i=cur_pos;i<LENGTH_A;i++)
        {
            if(X[i] == X[i+1])
            {
                count++;
            }
            else
            {
                cur_pos += count;
                sprintf(encoded_buff + strlen(encoded_buff), "%c", ch);
                sprintf(encoded_buff + strlen(encoded_buff), "%d", count);
                break;
            }
        }
    }

/*
    for(int i=0;i<LENGTH_A;i++)
        printf("%c",encoded_buff[i]);
    printf("\n");
*/
    return strlen(encoded_buff);
}

int main() {
    scanf("%s", A);
    LENGTH_A = strlen(A);

    char shifted_A[11] = "";
    char src_buff[11] = "";

    memcpy(src_buff, A, LENGTH_A);

    for(int i=0;i<LENGTH_A;i++)
    {    
        shift(shifted_A, src_buff);
        int ret = RunLengthEncode(shifted_A);
        ans = min(ret,ans);

        memset(src_buff,0,sizeof(src_buff));
        memcpy(src_buff, shifted_A, LENGTH_A);
    }

    printf("%d\n", ans);
    // for(int i=0;i<LENGTH_A;i++) printf("%c ", shifted_A[i]);

    return 0;
}