/*
Here we are finding the floor of an element.
FLOOR:- Floor of an element is the element itself if it is present in the array
else the greatest element which is smaller than the given element.
Eg:- for 5.6 the floor is 5 and ceil is 6 
lets consider an array :- [1,4,6,8,9] ,
=> if we search for floor(5) 
then we should get element 4 as answer since 5 is not present in 
the given array , and the greatest of {1,4} is 4 which is smaller than 5.
=>if we search for floor(6) 
then we should get element 6 as answer since it is present in the given array.
*/


/*
Here the intution is:-
if we get a match for the given element then we should return that index.
else we should continue our search.

Here we have 3 cases:-

here we maintain a res variable to store the greatest element index,smaller
than the given element(sKey).

1:- If we get match for element in the search itself , then we can return its index
2:- If sKey is greater than mid element then we check whether the current element 
is greater than v[res] then we change the res to current index, and move 
the start pointer to mid+1.
3:- If the sKey is smaller than mid element , then we move the end pointer
to mid-1 and continue search process as like in binary search.
*/

#include<bits/stdc++.h>
using namespace std;
int floorOfEle(vector<int> v ,int start,int end, int sKey){
    int mid,res;
    v[res]=-1;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey)   return mid;
        else if(v[mid]<sKey){
            if(v[mid]>v[res]) res=mid;
            start = mid+1;
        }
        else  end=mid-1;
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
    cout<<"Enter the element to find its Floor:"; 
    int skey; 
    cin>>skey;
    int result = floorOfEle(v,0,v.size()-1,skey);
    cout<<"floor of  "<<skey<<" is " <<v[result]<<endl;
    return 0;
}