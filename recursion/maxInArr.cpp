#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

int maxi(vector<int> &v,int ind)                                  
{

    if(ind==v.size()-1) return v[ind];
    return max(v[ind],maxi(v,ind+1));
}
int main()
{
    vector<int> v={6,2,1,4,0};
    cout<<maxi(v,0);
    return 0;
}