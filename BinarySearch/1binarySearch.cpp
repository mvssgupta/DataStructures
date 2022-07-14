#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> v ,int start,int end, int sKey){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey)   return mid;
        else if(v[mid]<sKey)  start = mid+1;
        else  end=mid-1;
    }
    return -1;
}
int main(){
    // vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    // int result = binarySearch(v,0,9,1);  //STATIC INPUT
     vector<int> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    cout<<"Enter the element to be found:"; int skey; cin>>skey;
    int result = binarySearch(v,0,v.size()-1,skey);
    if(result!=-1) cout<<"Element found at : "<<result<<endl;
    else cout<<"Element not found"<<endl;
    return 0;
}