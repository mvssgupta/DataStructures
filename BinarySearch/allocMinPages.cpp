#include<bits/stdc++.h>
using namespace std;
bool allocation(vector<int> &A, int pages, int students) {
    int cnt = 0;
    int sumAllocated = 0; 
    for(int i = 0;i<A.size();i++) {
        if(sumAllocated + A[i] > pages) {
            cnt++; 
            sumAllocated = A[i];
            if(sumAllocated > pages) return false; 
        }
        else {
            sumAllocated += A[i];
        }
    }
    if(cnt < students) return true; 
    return false; 
}
int allocMinPages(vector<int> v , int k){
    int low=v[0],sum=accumulate(v.begin(),v.end(),0),high=sum,result=-1;
    while(low<=high){
        int mid=low + (high-low)/2;
        if(allocation(v,mid,k)){
            result = mid;
            high=mid-1;
        }
        else
            low = mid+1;
    }
    return result;
}
int main(){
    vector<int> v = {12,34,67,90};
    cout<<allocMinPages(v,2);           //?prints 113 as answer for this input
    return 0;
}









// bool allocation(vector<int> v ,int barrier ,int n,int k){
//     int allocStudents = 1,pages=0;
//     for(int i=0;i<n;i++){
//         if(v[i]>barrier) return false;
//         if(pages+v[i]>barrier){
//             allocStudents+=1;
//             pages+=v[i];
//         }
//         else   
//             pages=v[i];
//     }
//     if(allocStudents>k) return false;
//     return true;
// }