#include <iostream>
#include <cstring>

using namespace std;

//    5
// 4  1  3
//    2
//    6

// left (2=3, 3=4, 4=6, 6=2) 
//    5
// 1  3  6
//    2
//    4

// Down  (1=6, 3=1, 5=3, 6=5)
//   4 
// 1 5 6
//   3
//   2

// Up  (1=3,3=5, 5=6, 6=1)
//   5
// 1 3 6
//   2
//   4

// Right (3=2, 4=3, 6=4, 2=6) 

int dice[7] = {0,5,4,1,3,2,6};
int tmp[7] = {0,};
int map[101][101];
int N,M;
int r,c;
char DIR[10001];
int ans = 0;

int roll(char dir)
{
    memcpy(tmp,dice,sizeof(dice));
    
    if(dir == 'L')
    {
       if(c-1 < 1) return -1;

       map[r][c] = dice[6];

       dice[2] = tmp[3];
       dice[3] = tmp[4];
       dice[4] = tmp[6];
       dice[6] = tmp[2];
       c--; 
    }
    else if(dir == 'R')
    {
        if(c+1 > N) return -1;

        map[r][c] = dice[6];

        dice[3] = tmp[2];
        dice[4] = tmp[3];
        dice[6] = tmp[4];
        dice[2] = tmp[6];
        c++;
    }
    else if(dir == 'U')
    {
        if(r-1 < 1) return -1;
        
        map[r][c] = dice[6];
        
        dice[1] = tmp[3];
        dice[3] = tmp[5];
        dice[5] = tmp[6];
        dice[6] = tmp[1];
        r--;
    }
    else if(dir == 'D')
    {
        if(r+1 > N) return -1;
        
        map[r][c] = dice[6];
        
        dice[3] = tmp[1];
        dice[5] = tmp[3];
        dice[6] = tmp[5];
        dice[1] = tmp[6];
        r++;
    }
    return 1;
}

int main() {
    scanf("%d %d %d %d", &N, &M, &r, &c);
    
    for(int i=0;i<M;i++)
        cin >> DIR[i];


    for(int i=0;i<M;i++)
    {
        int ret = 0;
        ret = roll(DIR[i]);
    }
    map[r][c] = dice[6];

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(map[i][j])
                ans+= map[i][j];
        }
    }    

    printf("%d\n", ans);

    return 0;
}