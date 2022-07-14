#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
void findClosestElements(vector<int>& arr, int k, int x) {
    vector<pair<int,int>> v;
    for(int i=0;i<arr.size();i++){
        v.push_back({abs(arr[i]-x),arr[i]});
    }
    priority_queue<pair<int,int>> maxh;
    for(int i=0;i<arr.size();i++){
        maxh.push({v[i].first,v[i].second});
        if(maxh.size()>k) maxh.pop();
    }
    arr.clear();
    while(!maxh.empty()){
        arr.push_back(maxh.top().second);
        maxh.pop();
    }
    sort(arr.begin(),arr.end());
    for(auto i:arr){
        cout<<i<<" ";
    }
    // return arr;
}
int main(){
    vector<int> v = {1,2,3,4,5};
    int k=4,x=3;
    findClosestElements(v,k,x);
    return 0;
}









