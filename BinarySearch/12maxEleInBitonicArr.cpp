#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> v ,int start,int end){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(mid>0 && mid<v.size()-1) {
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1])
                return mid;
            else if(v[mid-1]>v[mid])
                end=mid-1;
            else 
                start=mid+1;
        }
        else if(mid==0){
            if(v[mid]>v[mid+1])
                return mid;
            return mid+1;
        }
        else if(mid==v.size()-1){
            if(v[mid]>v[mid-1])
                return mid;
            return mid-1;
        }
    }
    return 0;
}
int main(){
     vector<int> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    int result = binarySearch(v,0,v.size()-1);
    cout<<"peak element in the given bitonic array : "<<v[result]<<endl;
    return 0;
}

