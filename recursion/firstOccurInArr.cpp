#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
int rec(vector<int> &v,int ind,int element)                                   
{
    if(v[ind]==element) return ind;
    else if(ind==v.size()) return -1;
    return rec(v,ind+1,element);
}
int main()
{
    vector<int> v={2,3,9,8,7,6,4,2,8};
    int findEle;
    cout<<"Enter the element for which first occurence is to be found:";
    cin>>findEle;
    int ans;
    if((ans = rec(v,0,findEle))!=-1) cout<<"First occurence of "<<findEle<<" is at index:"<<ans<<endl;
    else cout<<"Element not found"<<endl;
    return 0;
}