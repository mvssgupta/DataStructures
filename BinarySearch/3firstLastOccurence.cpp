//* i) first and last occurence of an element
//* ii) count of an element

#include<bits/stdc++.h>
using namespace std;
int firstbinarySearch(vector<int> v ,int start,int end, int sKey){
    int mid,firstOccur=-1;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey){
            firstOccur = mid;
            end = mid-1;
        }
        else if(v[mid]<sKey){
            start = mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return (firstOccur!=-1)?firstOccur:-1;
}
int lastbinarySearch(vector<int> v ,int start,int end, int sKey){
    int mid,lastOccur=-1;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey){
            lastOccur = mid;
            start = mid+1;
        }
        else if(v[mid]<sKey){
            start = mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return (lastOccur!=-1)?lastOccur:-1;
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);
    }
    cout<<"Enter the element to be found:";
    int skey;
    cin>>skey;
    int result1 = firstbinarySearch(v,0,v.size()-1,skey);
    int result2 = lastbinarySearch(v,0,v.size()-1,skey);
    if(result1!=-1){
        cout<<"1st Occurence of Element found at : "<<result1<<endl;
    }
    if(result2!=-1){
        cout<<"Last Occurence of Element found at : "<<result2<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    cout<<"Count of "<<skey<<" is "<<result2-result1+1<<endl;
    return 0;
}