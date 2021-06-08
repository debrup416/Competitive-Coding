#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(da,db) if(abs(da-db) < le-9)
#define pi pair<ll,ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back
 
int n,m;
 
void is_room(std::vector<std::vector<char> > &v,int row,int col)
{
    if(row<0 || row>=n || col<0 || col>=m || v[row][col]=='#')
        return ;
    v[row][col]='#';
    is_room(v,row-1,col);
    is_room(v,row,col-1);
    is_room(v,row+1,col);
    is_room(v,row,col+1);
}
 
int solve(std::vector<std::vector<char> > v)
{
    int room=0,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[i][j]=='.'){
                is_room(v,i,j);
                room++;
            }
        }
    }
    return room;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin>>n>>m;
    std::vector<std::vector<char> > v;
    for(i=0;i<n;i++)
    {
        std::vector<char> temp(m);
        for(j=0;j<m;j++)
        {
            cin>>temp[j];
        }
        v.pb(temp);
        temp.clear();
    }
    
    cout<<solve(v);
 
 
     
    return 0; 
}
 




