#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& v, int target) {
    if(v.size()==0) return {-1,-1};
    int lwr = lower_bound(v.begin(),v.end(),target)-v.begin();
    int upr = upper_bound(v.begin(),v.end(),target)-v.begin();
    if(lwr == v.size() || v[lwr] != target) return {-1,-1};
    else return {lwr,upr-1};
}
int main(){
    vector<int> v = {2,2};
    vector<int> res = searchRange(v,3);
    for(auto i:res) cout<<i<<" ";
    return 0;
}