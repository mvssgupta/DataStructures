#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

int rec(vector<int> &v,int ind,int ans,int element)                                  
{
    if(ind==v.size())
    {
        if(ans!=-1) return ans;
        else return -1;
    }
    if(v[ind]==element) ans=ind;
    return rec(v,ind+1,ans,element);
}
int main()
{
    vector<int> v={2,3,9,8,7,6,4,2,8};
    int findEle;
    cout<<"Enter the element for which last occurence is to be found:";
    cin>>findEle;
    int res;
    if((res=rec(v,0,-1,findEle))!=-1) cout<<"Last occurence of "<<findEle<<" is found at index:"<<res<<endl;
    else cout<<"Element not found"<<endl;
    return 0;
}