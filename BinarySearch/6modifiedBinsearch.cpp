#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> v ,int start,int end, int sKey){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey)   return mid;
        if(v[mid-1]==sKey)   return mid-1;
        if(v[mid+1]==sKey)   return mid+1;
        else if(v[mid]<sKey)   start = mid+2;
        else  end=mid-2;
    }
    return -1;
}
int main(){
    vector<int> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    cout<<"Enter the element to be found:"; int skey; cin>>skey;
    int result = binarySearch(v,0,v.size()-1,skey);
    if(result!=-1) cout<<"Element found at : "<<result<<"th index"<<endl;
    else cout<<"Element not found"<<endl;
    return 0;
}



/*
Here the element can be at i'th position or i-1 or i+1 positions
so based on that we have to return the index of the element to be found
*/


/*
5
5 10 30 20 40
Enter the element to be found:20
Element found at : 3
*/