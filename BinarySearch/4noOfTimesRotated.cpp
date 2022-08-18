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