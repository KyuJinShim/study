#include <iostream>

using namespace std;

int n, t;
int u[200];
int d[200];
int tmp_u[200];
int tmp_d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    for(int i=1;i<=t;i++)
    {
        // backup
        for(int j=0;j<n;j++)
        {
            tmp_u[j] = u[j];
            tmp_d[j] = d[j];
        }
        
        for(int j=1;j<n;j++)
        {
            u[j] = tmp_u[j-1];
            d[j] = tmp_d[j-1];
        }

        u[0] = tmp_d[n-1];
        d[0] = tmp_u[n-1];
    }

    for(int i=0;i<n;i++)
        printf("%d ",u[i]);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d ",d[i]); 

    return 0;
}
