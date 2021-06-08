#include<bits/stdc++.h>
using namespace std;

bool isValid(int board[][10],int row,int col,int N)
{
    for(int i=0;i<col;i++)
    {
        if(board[row][i]==1)
                return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
            if(board[i][j])
                    return false;
    for(int i=row,j=col;i<N && j>=0;i++,j--)
            if(board[i][j]) 
                    return false;

}

bool NQueen(int board[][10],int col, int N)
{
    if(col>=N)
            return true;
    for(int i=0;i<N;i++)
    {
        if(isValid(board,i,col,N))
        {
            board[i][col]=1;
            if(NQueen(board,col+1,N))
                    return true;
            board[i][col]=0;
        }
    }
    return false;
}

void pnt(int board[][10],int N)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }

}

bool solution( )
{
     int board[10][10];
     int N;
     cin>>N;
     memset(board,0,sizeof(board));
     if(NQueen(board,0,N)==false)
        return false;
    pnt(board,N);
    return true;
}

int main()
{
    solution();
}




