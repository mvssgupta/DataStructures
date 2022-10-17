//!next greater right element

#include<bits/stdc++.h>
using namespace std;
vector<long long> NGE(vector<long long> arr){
    vector<long long> ans; 
    stack <long long> s; 
    for (int i=arr.size()-1;i>=0;i--){

        //if the stack is empty then  push_back '-1' into the ans vector
        if(s.empty()) ans.push_back(-1);  

        //if stack is not empty and the current element is smaller than stack top then push_back stack top into the ans vector
        else if (!s.empty() && s.top()>arr[i]) ans.push_back(s.top()); 

        //if stack is not empty and the current element is greater than stack top 
        else if (!s.empty() && s.top()<=arr[i]) 
        {

            //then pop the top of the stack until the top is greater than current element
            while(!s.empty() && s.top()<=arr[i]) 
                s.pop();
            
            //after poping the elements if we found that the stack is empty that means
            //there is no greater element present in the right for the current element
            //so  push_back '-1' into the ans vector
            if (s.empty()) ans.push_back(-1);
            
            //if stack is not empty then push_back the top of the stack into the ans vector
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