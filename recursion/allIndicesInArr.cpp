#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

int allIndices(vector<int> &v,vector<int> &res,int ind, int element)
{
    if(ind==v.size())
        return 0;
    if(v[ind]==element) res.push_back(ind);
    return allIndices(v,res,ind+1,element);
}

int main()
{
    vector<int> v={2,3,9,8,7,6,4,2,8};
    vector<int> res;
    int findEle;
    cout<<"Enter the element for which all its occurences are to be found:";
    cin>>findEle;
    allIndices(v,res,0,findEle);
    cout<<"The element "<<findEle<<" found at the following indices:"<<endl;
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}