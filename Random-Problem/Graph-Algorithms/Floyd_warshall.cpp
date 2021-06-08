#include<bits/stdc++.h>
using namespace std;

int vertex;  

void Floyd_Warshall(vector<vector<int>> & matrix)
{
    for(int k=0;k<vertex;k++)
    {
        for(int i=0;i<vertex;i++)
        {
            for(int j=0;j<vertex;j++)
            {
                if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX)
                    continue;
                else
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    for(int i=0;i<vertex;i++)
    {
        if(matrix[i][i]<0)
        {
            cout<<"Negative cycle present\n";
            return ;
        }
    }
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
            cout<<i<<" to "<<j<<" distane : "<<matrix[i][j]<<"\n";
    }
}

int main()
{
    int edge;
    cin>>vertex>>edge;
    vector<vector<int>> matrix( vertex , vector<int> (vertex,INT_MAX )); 
    for(int i=0;i<vertex;i++)
        matrix[i][i]=0;

    for(int i=0;i<edge;i++)
    {
        int src,dst,cost;
        cin>>src>>dst>>cost;
        matrix[src][dst]=cost;
    }
    Floyd_Warshall(matrix);
    return 0;

}


