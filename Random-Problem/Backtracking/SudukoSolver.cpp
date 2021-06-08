#include<bits/stdc++.h>
using namespace std;


void pnt(int board[][20],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }

}

bool checkRow(int board[][20],int row,int num,int N)
{
    for(int col=0;col<N;col++)
        if(board[row][col]==num)
            return true;
    return false;
}
 
bool checkCol(int board[][20],int col,int num,int N)
{
    for(int row=0;row<N;row++)
        if(board[row][col]==num)
            return true;
    return false;

}

bool checkBox(int board[][20],int strow,int stcol,int num,int N)
{
    for(int row=0;row<sqrt(N);row++)
    {
        for(int col=0;col<sqrt(N);col++)
        {
            if(board[row+strow][col+stcol]==num)
                return true;
        }
    }
    return false;
}

bool isSafe(int board[][20],int row,int col,int num,int N)
{
    return !checkRow(board,row,num,N) && !checkCol(board,col,num,N) && !checkBox(board,row-row%3,col-col%3,num,N);

}

bool findUnassigned(int board[][20],int &row,int &col,int N)
{
    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
        {
            if(board[row][col]==0)
                return true;
        }
    }
    return false;
}

bool suduko(int board[][20],int N)
{
    int row,col;
    if(!findUnassigned(board,row,col,N))
        return true;
    for(int num=1;num<=N;num++)
    {

        if(isSafe(board,row,col,num,N)){
            board[row][col]=num;
             if(suduko(board,N))
            return true;

        board[row][col]=0;
        }

    }
return false;
}

void solve()
{
    int i,N,j,board[20][20];
    cin>>N;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }
    if(suduko(board,N))
            pnt(board,N);
    else
        cout<<"Not Possible\n";
}

int main()
{
    solve();
}




