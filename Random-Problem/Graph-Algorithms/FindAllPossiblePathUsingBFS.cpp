#include<bits/stdc++.h>
using namespace std;

int isNotVisted(int x,vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x)
            return 0;
    }
    return 1;
}
int main()
{
    vector<int>path;
    queue<vector<int>>q;
    int N,i,j,val;
    cin>>N;
    vector<int>vec[N];
    for(i=0;i<N;i++)
    {
        cin>>j;
        while(j--)
        {
            cin>>val;
            vec[i].push_back(val);
        }
    }

    int src,dest;
    cin>>src>>dest;
    vector<int>dummy;
    dummy.push_back(src);
    q.push(dummy);
    while(!q.empty())
    {
     path=q.front();
        q.pop();
        int lastNode=path[path.size()-1];

        if(lastNode==dest)
        {
            for(i=0;i<path.size();i++)
                cout<<path[i]<<" ";
            cout<<"\n";
        }

        else
        {
            for(i=0;i<vec[lastNode].size();i++)
            {
               if(isNotVisted(vec[lastNode][i],path))
               {
                 vector<int>newpath(path);
                 newpath.push_back(vec[lastNode][i]);
                 q.push(newpath);
               }
            }
        }
    }
    
}


