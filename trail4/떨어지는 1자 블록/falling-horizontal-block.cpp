#include <iostream>
using namespace std;

int N,M,K;
int map[101][101];
// block size : 1xM
// block pos : from K to K+M-1
int dy = 1;

void fall()
{
    int y = 0;
    while(1)
    {
        int moved = 0;
        bool blocked = false;
        bool outOfRange = false;

        for(int x=0;x<M;x++)
        {
            if(y+1 > N)
            {
                outOfRange = true;
                break;
            }
            
            if(map[y+1][K+x])
            {
                blocked = true;
            }
        }    
        if(blocked == false && outOfRange == false)
        {
            y++; //check current row
            moved = 1;
        }
        
        if(!moved)
        {
            break;
        }
    }
    
    for(int x=0;x<M;x++)
    {
        map[y][K+x] = 1;
    }   
}

int main() {
    scanf("%d %d %d", &N,&M,&K);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }

    fall();
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}