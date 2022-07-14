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
    //if the differnce from both the neighbouring elements are equal the 
    // I'm returning the first element. (since I used ''>=' in the below code)
    // If you want to return second element the you can simply use '>' symbol
    if(abs(v[start]-sKey)>=abs(v[end]-sKey)) //* (>=)
        return end;
    else
        return start;
}
int main(){
     vector<int> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    cout<<"Enter the key value :"; int skey; cin>>skey;
    int result = binarySearch(v,0,v.size()-1,skey);
    cout<<"The minimum difference can be obtained when given key is subtracted from "<<v[result]<<endl;
    return 0;
}