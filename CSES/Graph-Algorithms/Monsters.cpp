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
std::vector<pair<int,int>> monstar;
std::vector<std::vector<int> > grid;
pair<int,int>si,se;
map<pair<int,int>,pair<int,int>>mp;
std::vector<pair<int,int>> moves={{-1,0},{1,0},{0,1},{0,-1}};
 
int isValid(int x,int y, int timer)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return 0;
    if(grid[x][y]<=timer)
        return 0;
    return 1;
}
 
int is_escape(int x,int y,int timer)
{
    if(!isValid(x,y,timer))
        return false;
    if(x==0 || x== n-1 || y==0 || y==m-1)
        return true;
    return false;
}
 
bool bfs_escape()
{
    queue<pair<pair<int,int>,int>>q;
    q.push(mk(si,0));
    mp[si]={-1,-1};
    while(!q.empty())
    {
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int timer=q.front().second;
        timer++;
        q.pop();
        for(auto mv:moves)
        {
            int tx=cx+mv.first;
            int ty=cy+mv.second;
            if(is_escape(tx,ty,timer)){
                mp[{tx,ty}]={cx,cy};
                se={tx,ty};
                return true;
            }
            if(isValid(tx,ty,timer)){
                mp[{tx,ty}]={cx,cy};
                grid[tx][ty]=timer;
                q.push({{tx,ty},timer});
            }
        }
    }
    return false;
}
 
void pre_process()
{
    queue<pair<pair<int,int>,int>>q;
    for(auto m:monstar)
        q.push(mk(m,0));
 
    while(!q.empty())
    {
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int timer=q.front().second;
        timer++;
        q.pop();
        for(auto mv:moves)
        {
            int tx=cx+mv.first;
            int ty=cy+mv.second;
            if(isValid(tx,ty,timer)){
                grid[tx][ty]=timer;
                q.push({{tx,ty},timer});
            }
        }
    }
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++)
        grid[i].resize(m,0);
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='A')
                si={i,j};
            else if(c=='.')
                grid[i][j]=INT_MAX;
            else if(c=='M')
                monstar.pb(mk(i,j));
 
        }
    }
 
    if(si.first==0 || si.second==0 || si.first==n-1 || si.second==m-1)
    {
        cout<<"YES\n";
        cout<<0;
        return 0;
    }
 
    pre_process();
 
    if(!bfs_escape())
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    pair<int,int>tmp=se;
    pair<int,int>tmp1=mp[se];
    pair<int,int>ed={-1,-1};
    std::vector<char> ans;
 
    while(tmp1!=ed)
    {
     if((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('R');
    }
    if((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('L');
    }
    if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
    {
      ans.push_back('D');
    }
    if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
    {
      ans.push_back('U');
    }
    tmp = mp[tmp];
    tmp1 = mp[tmp];
 
    }
     reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(auto c: ans)
  {
    cout << c;
  } 
 
 
 
     // for(auto z:grid)
     // {
     //    for(auto x:z)
     //        cout<<x<<" ";
     //    cout<<"\n";
     // }
    
     
    return 0; 
}
 



