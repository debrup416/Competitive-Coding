#include<bits/stdc++.h>
using namespace std;
 
void pnt(int nums[],char symb[],int k)
{
    int i;
    for( i=1;i<k;i++)
            cout<<nums[i-1]<<" "<<symb[i]<<" ";
        cout<<nums[i-1];
        cout<<"\n";
} 

void makeEquation(int nums[],int k,int N,int R,char symb[])
{
    int temp=R;
    if(k==N-1)
    {

        if(nums[N-1]==R)
            pnt(nums,symb,k);
        return;
    }
    else
    {
        R+=nums[k];
        symb[k]='+';
        makeEquation(nums,k+1,N,R,symb);
        temp-=nums[k];
        symb[k]='-';
        makeEquation(nums,k+1,N,temp,symb);
    }
}

void solution()
{
    int N,nums[30];
    char symb[30]="";
    cin>>N;
    for(int i=0;i<N;i++)
            cin>>nums[i];
    makeEquation(nums,1,N,nums[0],symb);

}

int main()
{
    solution();
}





