#include<bits/stdc++.h>
using namespace std;
vector<int> PreMaxEle(vector<int> arr){  //!used to get maximum element in left subarray
    vector<int> ans; 
    stack <int> s; 
    for (int i=0;i<arr.size();i++){
        if(s.empty()) {
            s.push(arr[i]);
            ans.push_back(0);
        }
        else if(!s.empty() && s.top()>arr[i]) ans.push_back(s.top());
        else if(!s.empty() && s.top()<=arr[i]){
            ans.push_back(s.top());
            s.pop();
            s.push(arr[i]);
        }
        if(arr[i]>s.top()) s.push(arr[i]); 
    }
    return ans;
}
vector<int> NextMaxEle(vector<int> arr){  //!used to get maximum element in right subarray
    vector<int> ans; 
    stack <int> s; 
    for (int i=arr.size()-1;i>=0;i--){
        if(s.empty()) {
            s.push(arr[i]);
            ans.push_back(0);
        }
        else if(!s.empty() && s.top()>arr[i]) ans.push_back(s.top());
        else if(!s.empty() && s.top()<=arr[i]){
            ans.push_back(s.top());
            s.pop();
            s.push(arr[i]);
        }
        if(arr[i]>s.top()) s.push(arr[i]); 
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> v1 = {3,0,0,2,0,4};   //[4,2,0,3,2,5] =>9   //[0,1,0,2,1,0,1,3,2,1,2,1] =>6
    vector<int> leftMax = PreMaxEle(v1);
    vector<int> rightMax = NextMaxEle(v1);
    int waterInTrap = 0;
    for(int i=0;i<v1.size();i++){
        int water  = min(leftMax[i],rightMax[i])-v1[i];
        waterInTrap += (water>0)?water:0;
    }
    cout<<waterInTrap<<endl;
    return 0;
}