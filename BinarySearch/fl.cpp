#include<bits/stdc++.h>
using namespace std;

/*
here using lower_bound and upper_bound functions in stl
we are returning the first and last occurence of given target element 
in the given array.


Here the intution is if we get the lower_bound of a number as last element then
we can tell that its upper_bound is not present in the array , then we have to 
return {-1,-1} as our answer otherwise we have to return the 
respective first and last occurence of the given element.
*/
vector<int> searchRange(vector<int>& v, int target) {
    if(v.size()==0) return {-1,-1};
    int lwr = lower_bound(v.begin(),v.end(),target)-v.begin();
    int upr = upper_bound(v.begin(),v.end(),target)-v.begin();
    if(lwr == v.size() || v[lwr] != target) return {-1,-1};
    else return {lwr,upr-1};
}
int main(){
    vector<int> v = {0,1,2,2,2,3,4,5,5,6,6,6};
    vector<int> res = searchRange(v,4);
    for(auto i:res) cout<<i<<" ";
    return 0;
}