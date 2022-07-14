#include<bits/stdc++.h>
using namespace std;
int res=0;
int binarySearch(vector<int> v ,int start,int end, int sKey){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey)   return mid;
        else if(v[mid]<sKey){
            if(v[mid]>res) res=v[mid];
            start = mid+1;
        }
        else  end=mid-1;
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
    cout<<"Enter the element to find its Floor:"; 
    int skey; 
    cin>>skey;
    int result = binarySearch(v,0,v.size()-1,skey);
    if(result!=-1) cout<<"floor of  "<<skey<<" is " <<v[result]<<endl;
    else cout<<"Floor of "<<skey<<" is "<<res<<endl;
    return 0;
}