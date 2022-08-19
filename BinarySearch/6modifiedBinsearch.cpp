/*
Here we have to find an element in nearly sorted array.

Nearly sorted array : In a nearly sorted array , the element which is 
to be at index i in sorted array may be at i-1 or i or i+1 position.

for example :-  Nearly sorted array: 5 10 30 20 40
                sorted order of the above array: 5 10 20 30 40
                from here we can observe that , the element 20 should be at index=2
                but it is at 2+1= 3 in nearly sorted array which is (index+1) position and also ,
                the element 30 should be at index=3 but in nearly sorted array
                it was at 3-1=2 which is index-1,
*/


/*
Intution of the algorith :-

since the element can be present at i,i-1,i+1 in nearly sorted array,
we have to calculate the mid and we have to search at mid , mid-1 , mid+1 position
to find any element.
1:- If the element at mid is less than search key then we have to make start=mid+2
and continue to search in right part of mid , here we are doing mid+2 instead of mid+1
why because , we have already search at mid+1 position, so we are making the start = mid+2 position

2:-If the element at mid is greater than search key then we have to make end=mid-2
and continue to search in left part of mid.


If element not found , we have to return -1.
*/


#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> v ,int start,int end, int sKey){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey)   return mid;

        /// while checking mid-1 location , we have to 
        /// verify that whether mid is greater than start or not , 
        ///if it is start then start-1(Alias mid-1) is not a valid location , so we have to take care of it.
        if(mid>start && v[mid-1]==sKey)   return mid-1;

        /// here also, we have to check whether mid+1 location is valid or not.
        /// if mid points to end then mid+1 is not a valid location, so we have 
        /// to check whether the mid is less than end or not.
        if(mid<end && v[mid+1]==sKey)   return mid+1;

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