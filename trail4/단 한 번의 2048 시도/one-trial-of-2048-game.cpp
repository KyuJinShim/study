#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 4;
char dir;

int map[4][4];
int result[4][4];

void process_row(int row, char dir, vector<int> v)
{
    if(dir == 'L')
    {
        int x = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == v[i+1])
            {
                result[row][x] = v[i] * 2;
                i+=1;
                x++;
            }
            else
            {
                result[row][x] = v[i];
                x++;
            }
        }
    }
    else if(dir == 'R')
    {
        reverse(v.begin(),v.end());

        int x = 3;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == v[i+1])
            {
                result[row][x--] = v[i] * 2;
                i+=1;
            }
            else
            {
                result[row][x--] = v[i];
            }
        }
    }
}

void process_col(int col, char dir, vector<int> v)
{
    if(dir == 'U')
    {
        int y = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == v[i+1])
            {
                result[y++][col] = v[i] * 2;
                i+=1;
            }
            else
            {
                result[y++][col] = v[i];
            }
        }        
    }
    else if(dir == 'D')
    {
        reverse(v.begin(),v.end());
        int y=3;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == v[i+1])
            {
                result[y--][col] = v[i] * 2;
                i+=1;
            }
            else
            {
                result[y--][col] = v[i];
            }
        }
    }
}

vector<int> get_row(int row)
{
    vector<int> v;
    for(int x=0;x<N;x++)
    {
        if(map[row][x] != 0)
            v.push_back(map[row][x]);
    }
    return v;
}

vector<int> get_col(int col)
{
    vector<int> v;
    for(int y=0;y<N;y++)
    {
        if(map[y][col] != 0)
            v.push_back(map[y][col]);
    }
    return v;
}

int main(){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    cin >> dir;

    // case 'L' or 'R' : get numbers from row (into vector)
    if(dir == 'L' || dir == 'R')
    {
        for(int y=0;y<N;y++)
        {
            // get one row
            vector<int> row;
            row = get_row(y);

            // set to new map
            process_row(y, dir, row);
        }
    }
    else if(dir == 'U' || dir == 'D')
    {
        for(int x=0;x<N;x++)
        {
            // get one col
            vector<int> col;
            col = get_col(x);

            // set to new map
            process_col(x,dir,col);
        }
    }
    // case 'U' or 'D' : get numbers from col (into vector)

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}