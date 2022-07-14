#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> v ,int start,int end, int sKey){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey){
            return mid;
        }
        else if(v[mid]<sKey){
            start = mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
int SortArray(vector<int> v ,int start,int end){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        int next = (mid+1)%v.size();
        int pre = (mid+v.size() - 1)%v.size();
        if(v[mid]<=v[next] && v[mid]<=v[pre]){
            return mid;
        }
        if(v[start] < v[pre]){
            start = mid+1;
        }
        else if(v[next] < v[end]){
            end = mid-1;
        }
    }
    return 0;
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    int sKey;
    cin>>sKey;
    int index = SortArray(v,0,n-1);
    int result1 = binarySearch(v,0,index-1,sKey);
    int result2 = binarySearch(v,index,n-1,sKey);
    int res = max(result1,result2);
    if(res!=-1){
        cout<<"Element found at "<<res<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}


