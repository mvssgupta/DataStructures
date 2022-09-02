#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

vector<int> printSpiral(const vector<vector<int> > &Arr) {
    
    int Top,Bottom,Left,Right,dir;
    Top=0;
    Bottom=Arr.size()-1;
    Left=0;
    Right=Arr[0].size()-1;
    dir=0;
    int i;
    vector<int> ans;
    
    while(Top<=Bottom && Left<=Right)
    {
        if(dir==0)
        {
            for(i=Left;i<=Right;i++)
                ans.push_back(Arr[Top][i]);
            Top++;
        }
        else if(dir==1)
        {
            for(i=Top;i<=Bottom;i++)
                ans.push_back(Arr[i][Right]);
            Right--;
        }
        else if(dir==2)
        {
            for(i=Right;i>=Left;i--)
                ans.push_back(Arr[Bottom][i]);
            Bottom--;
        }
        else if(dir==3)
        {
            for(i=Bottom;i>=Top;i--)
                ans.push_back(Arr[i][Left]);
            Left++;
        }
        dir=(dir+1)%4;
    }
    return ans;
}

int main()
{
    vector<vector<int>> Arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    vector<int> res = printSpiral(Arr);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}