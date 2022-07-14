#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
vector<string> findRelativeRanks(vector<int>& score) {
    vector<string> ans;
    priority_queue<int> maxh;
    for(int i=0;i<score.size();i++){
        maxh.push(score[i]);
    }
    unordered_map<int,string> m;
    int count=4;
     if(!m.empty()){
        m[maxh.top()]="Gold Medal";
        maxh.pop();
    }
    if(!m.empty()){
        m[maxh.top()]="Silver Medal";
        maxh.pop();
    }
        if(!m.empty()){
        m[maxh.top()]="Bronze Medal";
        maxh.pop();
    }
    while(!maxh.empty()){
        m[maxh.top()]=to_string(count);
        maxh.pop();
        count++;
    }
    for(int i=0;i<score.size();i++){
        ans.push_back(m[score[i]]);
    }
    return ans;
}
int main(){
    vector<int> v = {5,4,3,2,1};
    vector<string> ans = findRelativeRanks(v);
    for(auto i : ans){
        cout<<i<<" "; 
    }
    return 0;
}


