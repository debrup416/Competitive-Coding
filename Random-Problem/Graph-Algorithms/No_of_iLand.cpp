#include<bits/stdc++.h>
using namespace std;

 void explore(int iLand[][100],int x,int y,int row,int col)
 {
     if(x<0 || x>=row || y<0 || y>=col || iLand[x][y]!=1)  
            return;
     iLand[x][y]=2;

     explore(iLand,x+1,y,row,col);
     explore(iLand,x,y+1,row,col);
    explore(iLand,x-1,y,row,col);
    explore(iLand,x,y-1,row,col);

 }

int main()
{
    int row,col,i,j,iLand[100][100];
    cin>>row>>col;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cin>>iLand[i][j];
        }
    }
    int count=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(iLand[i][j]==1)
            {
                explore(iLand,i,j,row,col);
                count++;
            }
        }
    }
    cout<<count<<"\n";

    return 0;
}


