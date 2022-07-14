#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
string frequencySort(string s) {
    string ans = "";
    unordered_map<char,int> m;
    priority_queue<pair<int,char>> maxh;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    for(auto i:m){
        maxh.push({i.second,i.first});
    }
    while(!maxh.empty()){
        auto pr = maxh.top();
        while(pr.first--){
            ans.push_back(pr.second);
        }
        maxh.pop();
    }
    return ans;
}
int main(){
   string str = "tree";
   string st =  frequencySort(str);
   cout<<st<<endl;
    return 0;
}

