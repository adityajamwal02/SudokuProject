#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Conditional Functional to choose for Safe Spot for the remaining grid numbers

bool isSafe(int mat[][9], int i, int j, int no, int n)
{
    //Check for rows and columns
    for(int k=0;k<n;k++)
    {
        if(mat[k][j]==no or mat[i][k]==no)
            return false;
    }

    //Check for SubGrid (SubGrid formula)
    int sx= (i/3)*3;
    int sy= (j/3)*3;

    for(int x=sx;x<sx+3;x++)
    {
        for(int y=sy;y<sy+3;y++)
        {
            if(mat[x][y]==no)
                return false;
        }
    }
    return true;
}


bool solveSudoku(int mat[][9], int i, int j, int n)
{
    //Base case
    if(i==n)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }

        return true;
    }

    //Recursive Case
    if(j==n)
    {
        return solveSudoku(mat, i+1, 0, n);
    }
    //Skip PreFilled Cells
    if(mat[i][j]!=0)
        return solveSudoku(mat, i, j+1, n);

    //Cell to be filled, try all possibilities
    for(int no=1;no<=9;no++)
    {
        if(isSafe(mat,i,j,no,n))
        {
            mat[i][j] = no;
            bool solveSubProblem = solveSudoku(mat,i,j+1,n);
            if(solveSubProblem==true)
                return true;
        }
    }
    //Backtrack step
    mat[i][j]=0;
    return false;
}


int main()
{
    int n=9;
    int mat[9][9]=
    {{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
    };

    if(!solveSudoku(mat, 0, 0, n))
        cout<<" No Solution Exists!";

return 0;
}
