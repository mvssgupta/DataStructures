/*
This problem is based on the concept - "Binary search on answer"
which means , though the array given is not sorted then also there
is a chance to apply binary search on it.


Here the problem is we are given an array(not sorted) and we have 
to find the peak element in the array .
we can return any one peak element in the array.


criteria for a peak element:- the element should be greater than its neighbours.

Intution is:-
we face two types here , one are edge cases which means element at 
first or last index may be the peak element and the other is the element
in between the first and last elements.

For an element in between first and last can have both neighbour elements,
but for element at first we should compare it with the right element and if
it is greater than its right element then we can return it as peak element.
similarly for an element at the end , we have only left element as neighbour
so if the left element is smaller ,then we can say the last element is 
a peak element.

*/
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> v ,int start,int end){
    if(v.size()==1) return 0; //if array has only one element
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(mid>0 && mid<v.size()-1) {
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1])     //checking for elements between first and last.
                return mid;
            else if(v[mid-1]>v[mid])
                end=mid-1;
            else 
                start=mid+1;
        }
        else if(mid==0){              //checking for element at first index
            if(v[mid]>v[mid+1])
                return mid;
            return mid+1;
        }
        else if(mid==v.size()-1){    //checking for element at last index
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
    cout<<"One of the Peak element is : "<<v[result]<<endl;
    return 0;
}









// //! bruteForce method to find peak element
// #include<bits/stdc++.h>
// using namespace std;
// int findPeakElement(vector<int>& nums) {
//     int count=0;
//     if(nums.size()==1) return 0;
//     else {
//         for(int i=0;i<nums.size();i++){
//             if(count==nums.size()-1){
//                 return count;
//             }
//             else{ 
//             if(nums[i]<nums[i+1])
//                 count++;
//             else
//                 break;
//         }
//         }
//     }
//     return count;
// }

// int main() {
//     vector<int> v;
//     int n; cin>>n;
//     for(int i=0;i<n;i++){
//         int k;
//         cin>>k;
//         v.emplace_back(k);              //DYNAMIC INPUT
//     }
//     int result = findPeakElement(v);
//     cout<<"One of the Peak element of the given elements are :"<<v[result]<<endl;
//     return 0;
// }






// //! my leetcode solution

// class Solution {
// public:
//     int findPeakElement(vector<int>& v) {
//         if(v.size()==1) return 0; //if array has only one element
//         int start=0,end=v.size()-1,mid;
//         while(start<=end){
//             mid = start + (end-start)/2;
//             if(mid>0 && mid<v.size()-1) {
//                 if(v[mid]>v[mid-1] && v[mid]>v[mid+1])   //checking whether it is peak element or not
//                     return mid;
//                 else if(v[mid-1]>v[mid])
//                     end=mid-1;
//                 else 
//                     start=mid+1;
//             }
//             else if(mid==0){    //if the peak element is at first position
//                 if(v[mid]>v[mid+1])
//                     return mid;
//                 return mid+1;
//             }
//             else if(mid==v.size()-1){   //if the peak element is at the last position
//                 if(v[mid]>v[mid-1])
//                     return mid;
//                 return mid-1;
//             }
//         }
//         return 0;
//     }
// };