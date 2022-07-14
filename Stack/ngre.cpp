//!next greater right element

#include<bits/stdc++.h>
using namespace std;
vector<long long> NGE(vector<long long> arr){
    vector<long long> ans; 
    stack <long long> s; 
    for (int i=arr.size()-1;i>=0;i--){
        if(s.empty()) ans.push_back(-1); 
        else if (!s.empty() && s.top()>arr[i]) ans.push_back(s.top()); 
        else if (!s.empty() && s.top()<=arr[i]) 
        {
            while(!s.empty() && s.top()<=arr[i]) 
                s.pop();
            if (s.empty()) ans.push_back(-1);
            else ans.push_back(s.top()); 
        }
        s.push(arr[i]); 
    }
    reverse(ans.begin(),ans.end()); 
    return ans;
  }
int main(){
    vector<long long int> v1 = {4,1,2};
    vector<long long int> ans = NGE(v1);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}