#include<bits/stdc++.h>
using namespace std;

bool isSafe(int M[][20],int i,int j,int N)
{
    if(i>=0 && i<N && j>=0 && j<N && M[i][j])
        return 1;
    return 0;
}

bool solve(int M[][20],int x,int y,int sol[][20],int N)
{
    if(x==N-1 && y==N-1)
    {
        sol[x][y]=1;
        return true;
    }
    if(isSafe(M,x,y,N))
    {
    sol[x][y]=1;
    if(solve(M,x,y+1,sol,N))
            return true;
    if(solve(M,x+1,y,sol,N))
            return true;
    sol[x][y]=0;
    return false;
    }
    return false;
}

void pnt(int sol[][20],int N)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool solveMerge(int M[][20],int N)
{
    int sol[20][20]={0};
    if(!solve(M,0,0,sol,N))
            return false;
      
    pnt(sol,N);
    return true;
}

int main()
{
     int arr[20][20];
     int i,j,N;
     cin>>N;
     for(i=0;i<N;i++)
     {
        for(j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
     }
     solveMerge(arr,N);
     return 0;
}





