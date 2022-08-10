#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

///subsequence def : A contiguous or non contigous sequence which follow the order
///for example : for [1 2 4]  the subsequenes are :- {},{1},{2},{4},{1,2},{1,4},{2,4},{1,2,4}
void findAllSubSeq(int i , vector<int> &v , int arr[],int n)
{
    if(i>=n)
    {
        for(auto i:v) cout<<i<<" ";
        cout<<endl;
        return;
    }
    v.push_back(arr[i]);

    ///take
    findAllSubSeq(i+1,v,arr,n);  //*consider an element

    v.pop_back();                //*remove that element

    ///not take
    findAllSubSeq(i+1,v,arr,n);  //*not considering that element
}
                                
int main()
{
    int arr[] = {3,1,2};
    vector<int> v;

    ///to get the length of arr we can we the syntax *(&arr+1) - arr
    ///here (&arr+1) points to the last element of the array , so by deferencing it we can get its index
    ///and arr is the first index address , so by subtracting them we can get the arr's length

    ///in general we use sizeof(arr)/sizeof(arr[0]) to get the arr length

    findAllSubSeq(0,v,arr,*(&arr+1)-arr);
    return 0;
}