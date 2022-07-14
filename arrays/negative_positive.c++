// the input array contains both positive and negative numbers 
// we have to arrange the array such that 
// all the negative numbers should be on left side and 
// all the postive numbers should be on right side.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ,k=-1,j=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(j=0;j<n;j++){
        if(arr[j]<0)
           swap(arr[++k],arr[j++]);
           // here we are pre incrementing k and post incrementing j
           // which means before swapping we are incrementing k and 
           // after swapping we are incrementing j
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}


//! sample input: 3 -2 5 -4 1 6
//! expected output: -2 -4 5 3 1 6