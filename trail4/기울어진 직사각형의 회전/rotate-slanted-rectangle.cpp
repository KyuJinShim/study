#include <iostream>
using namespace std;

int map[101][101];
int tmp_map[101][101];

int dy_d0[4] = {-1,-1,1,1};
int dx_d0[4] = {1,-1,-1,1};
int dy_d1[4] = {-1,-1,1,1};
int dx_d1[4] = {-1,1,1,-1};

int N;
int R, C;
int m1,m2,m3,m4;
int dir;
int tmp_r, tmp_c;

void copy_map(int dest[][101], int src[][101])
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}

void rotate(int m,int dir,int phase)
{
    for(int i=0;i<m;i++)
    {
        if(dir == 0)
        {
            tmp_r += dy_d0[phase];
            tmp_c += dx_d0[phase];
            map[tmp_r][tmp_c] = tmp_map[tmp_r + dy_d0[(phase+2)%4]][tmp_c + dx_d0[(phase+2)%4]];
        }
        else if(dir == 1)
        {
            tmp_r += dy_d1[phase];
            tmp_c += dx_d1[phase];            
            map[tmp_r][tmp_c] = tmp_map[tmp_r + dy_d1[(phase+2)%4]][tmp_c + dx_d1[(phase+2)%4]];
        }        
    }
}

void set_start(int dir, int phase)
{
    if(dir == 0)
    {
        map[tmp_r][tmp_c] = tmp_map[tmp_r + dy_d0[(phase+1)%4]][tmp_c + dx_d0[(phase+1)%4]];
    }
    else if(dir == 1)
    {
        map[tmp_r][tmp_c] = tmp_map[tmp_r + dy_d1[(phase+1)%4]][tmp_c + dx_d1[(phase+1)%4]];
    }    
}

int main()
{
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d %d %d %d %d %d %d", &R, &C, &m1, &m2, &m3, &m4, &dir);
    
    copy_map(tmp_map,map);
    
    tmp_r = R;
    tmp_c = C;
    
    set_start(dir,0);
    if(dir == 0)
        rotate(m1,dir,0);
    else
        rotate(m4,dir,0);
    
    set_start(dir,1);
    if(dir == 0)
        rotate(m2,dir,1);
    else
        rotate(m3,dir,1);
    
    set_start(dir,2);
    if(dir == 0)
        rotate(m3,dir,2);
    else
        rotate(m2,dir,2);
    
    set_start(dir,3);
    if(dir == 0)
        rotate(m4,dir,3);
    else
        rotate(m1,dir,3);
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}