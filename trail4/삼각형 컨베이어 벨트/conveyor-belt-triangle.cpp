#include <iostream>
using namespace std;

int N, T;

int a[200];
int b[200];
int c[200];

int tmp_a[200];
int tmp_b[200];
int tmp_c[200];

void solve()
{
    for(int t=1;t<=T;t++)
    {
        //backup
        for(int i=0;i<N;i++)
        {
            tmp_a[i] = a[i];
            tmp_b[i] = b[i];
            tmp_c[i] = c[i];
        }

        //move X[i] = X[i-1]
        for(int i=1;i<N;i++)
        {
            a[i] = tmp_a[i-1];
            b[i] = tmp_b[i-1];
            c[i] = tmp_c[i-1];
        }

        // set X[0] 
        a[0] = tmp_c[N-1];
        b[0] = tmp_a[N-1];
        c[0] = tmp_b[N-1];
    }
}

int main() {
    scanf("%d %d", &N, &T);
    for(int i=0;i<N;i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d", &b[i]);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d", &c[i]);
    }

    solve();

    for(int i=0;i<N;i++)
        printf("%d ", a[i]);
    printf("\n");
    for(int i=0;i<N;i++)
        printf("%d ", b[i]);
    printf("\n");
    for(int i=0;i<N;i++)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}