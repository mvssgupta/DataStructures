#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
int minSetSize(vector<int>& arr) {
    int arrSize = arr.size();
    priority_queue<int> maxh;
    unordered_map<int,int> m;
    for(auto i:arr){
        m[i]++;
    }
    int count=0,result=0;
    for(auto i:m){
        maxh.push(i.second);
    }
    
    while(count<arrSize/2){
        count+=maxh.top();
        maxh.pop();
        result+=1;
    }
    return result;
}
int main(){
    vector<int> v = {3,3,3,3,5,5,5,2,2,7};
    cout<<minSetSize(v);
    return 0;
}









