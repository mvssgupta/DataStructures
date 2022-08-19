#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

/*
we are given an sorted array and a key element ,
we have to find an element from the array such that the difference between
the key and the element from the array is minimum.

If we get two elements with same difference
we can return any one of them, either the first one or second.

eg:
6
1 2 3 6 8 10
key:- 7
here from both 6 and 8 we can get minimum difference , 
so we can return any one of them , in code I have wrote logic for returning
the first element, we can return second element also.
*/

int binarySearch(vector<int> v ,int start,int end, int sKey){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey)   return mid;
        else if(v[mid]<sKey)  start = mid+1;
        else  end=mid-1;
    }
    //if the differnce from both the neighbouring elements are equal then 
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