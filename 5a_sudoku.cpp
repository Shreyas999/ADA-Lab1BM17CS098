#include<bits/stdc++.h>
using namespace std;
int N;
int sqr=sqrt(N);
int grid[10][10];
bool isSafe(int row, int col, int num)
{
    int i,j;
    int srow,scol;
    for(i=0;i<N;i++)
    {
        if(grid[row][i]==num)
            return false;
    }
    for(i=0;i<N;i++)
    {
        if(grid[i][col]==num)
            return false;
    }
    srow = (row/3)*3;
    scol = (col/3)*3;
    for(i=srow; i<srow+sqr;i++)
    {
        for(j=scol;j<scol+sqr;j++)
        {
            if(grid[i][j]==num)
            {
                return false;
            }
        }
    }
    return true;
}

bool findUnassignedLocation(int *row,int *col)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(grid[i][j]==0)
            {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}
bool solveSudoku()
{
    int num;
    int row,col;
    if(!findUnassignedLocation(&row,&col))
        return true;
    for(num=1;num<=N;num++)
    {
        if(isSafe(row,col,num))
        {
            grid[row][col]=num;
            if(solveSudoku())
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}
int main()
{
    int i,j;
    cout<<"Enter the size:";
    cin>>N;
    cout<<"Enter the grid:\n";
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<"\n";
    if(solveSudoku())
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else
    {
        cout<<"No Solution";
    }

}
