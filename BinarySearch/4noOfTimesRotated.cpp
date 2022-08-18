/*
Here the intution is:-

after finding the mid , we have two cases:-
1:- we have to check whether it is smaller than it prev and next 
elements , if it is , then we can return its index as minimum element index .
from here , we can get the number  of elements to be rotated to make the array sorted
as follows ---> arr.size()-the returned val gives us the number of elements to be rotated

2:-If it is not our answer then we have to continue our search to find that element

here we have a problem , we know we have to check the remaining array , 
but we dont know in which side we have to search. 

for that :--
   1:- compare the first pointer and mid element if they are in sorted order(in general :ascending order)
   then we can move our first pointer to mid and continue our search in right part of array
   
   2:- In else case again compare the mid and end pointer , if they were in sorted order(in general :ascending order)
   then we have to move our end pointer to mid and continue our search in left part of array
*/


#include<bits/stdc++.h>
using namespace std;
int SortArray(vector<int> v ,int start,int end){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;

        /// we take (mid+1)%arrSize ,since if mid points to 
        /// last index then mid+1 will give us segmentation error(which is arrary index our of bound)
        /// so we are taking (mid+1)%arrSize which will not give us error
        int next = (mid+1)%v.size();

        /// here also same story, if mid points to start element
        /// then prev  = mid-1 given -1 , which causes segmentation error
        /// so we take prev = (mid+arrSize -1)%arrSize
        int pre = (mid+v.size() - 1)%v.size();
        if(v[mid]<=v[next] && v[mid]<=v[pre]){
            return mid;
        }
        if(v[start] <= v[mid]){
            start = mid;
        }
        else if(v[mid] <= v[end]){
            end = mid;
        }
    }
    return -1;
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    int result = SortArray(v,0,n-1);
    cout<<"Index of the minimum element in the array is: "<<result<<endl;
    cout<<"Number of elements need to be rotated clockwise to make the array sorted is "<<v.size()-result<<endl;
    return 0;
}


/*
for suppose the vector is 11 12 15 18 2 5 6 8
here we have to move 2 5 6 8 to start to make the vector sorted
so we find the index of 2 and return v.size()-index of 2
this gives us how many elements need to move to make 
the given vector sorted.
*/




/*
8 
11 12 13 14 15 16 17 2
Number of elements need to be rotated to make the array sorted is 1
*/



/*
6
11 12 13 14 2 3
Number of elements need to be rotated to make the array sorted is 2
*/