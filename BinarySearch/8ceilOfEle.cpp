/*
here we have to fing ceil of an element.
Ceil:- Ceil of an element is element itself if it is present in 
the given array ,
else the smallest element which is greater than given element
Eg:- for 5.6 the floor is 5 and ceil is 6 
lets consider an array :- [1,4,6,8,9] ,
=> if we search for Ceil(5) 
then we should get element 6 as answer since 5 is not present in 
the given array , and the smallest of {6,8,9} is 6 which is greater than 5.
=>if we search for Ceil(6) 
then we should get element 6 as answer since it is present in the given array.
*/


//Here the intution is similar to finding the floor of an element.
#include<bits/stdc++.h>
using namespace std;
int ceilOfEle(vector<int> v ,int start,int end, int sKey){
    int mid,res;
    v[res]=INT_MAX;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey)   return mid;
        else if(v[mid]<sKey) start = mid+1;
        else{
            if(v[mid]<v[res]) res=mid;
            end=mid-1;
        }
    }
    return res;
}
int main(){
     vector<int> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    cout<<"Enter the element to find its Ceil:"; 
    int skey; 
    cin>>skey;
    int result = ceilOfEle(v,0,v.size()-1,skey);
    cout<<"Ceil of  "<<skey<<" is " <<v[result]<<endl;
    return 0;
}