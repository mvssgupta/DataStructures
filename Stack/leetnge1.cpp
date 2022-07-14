#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        vector<int> ans; 
        vector<int> ans2;
        stack <int> s; 
        for (int i=nums.size()-1;i>=0;i--){
            if(s.empty()) ans.push_back(-1); 
            else if (!s.empty() && s.top()>nums[i]) ans.push_back(s.top()); 
            else if (!s.empty() && s.top()<=nums[i]) 
            {
                while(!s.empty() && s.top()<=nums[i]) 
                    s.pop();
                if (s.empty()) ans.push_back(-1);
                else ans.push_back(s.top()); 
            }
            s.push(nums[i]); 
        }
        reverse(ans.begin(),ans.end()); 
        for(int i=0;i<nums1.size();i++){
            int index = find(nums.begin(),nums.end(),nums1[i])-nums.begin();
            cout<<"index "<<i<<"->"<<index<<endl;
            ans2.push_back(ans[index]);
        }
        return ans2;
    }

    int main(){
    vector<int> v1 = {4,1,2};
    vector<int> v2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(v1,v2);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}