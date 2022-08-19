#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;


/*
This problem is combination of finding an element in infinite sorted array + 
finding the first occurence of an element.

here we are given with an infinte sorted binary array , which means the array 
contains only 0's and 1's in sorted order, we have to find the
first occurrenc of 1 in that array.
*/
int firstOccurence(vector<int>v,int start , int end)
{
    int sKey=1,res;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(v[mid]==1) 
        {
            res=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    return res;
}
int find1inInfinteSortedArr(vector<int>v)
{
    int start=0,end=1;
    while(v[end]!=1)
    {
        start=end;
        end=2*end;
    }
    return firstOccurence(v,start,end);
}
int main()
{
    vector<int> v={0,0,0,1,1};
    cout<<"First occurrence of 1 in the given infinte sorted array is at "<<find1inInfinteSortedArr(v)<<endl;
    return 0;
}