#include<bits/stdc++.h>
using namespace std;
int SortArray(vector<int> v ,int start,int end){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        int next = (mid+1)%v.size();
        int pre = (mid+v.size() - 1)%v.size();
        if(v[mid]<=v[next] && v[mid]<=v[pre]){
            return v.size()-mid;
        }
        if(v[start] <= v[pre]){
            start = mid+1;
        }
        else if(v[next] <= v[end]){
            end = mid-1;
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
    cout<<"Number of elements need to be rotated to make the array sorted is "<<result<<endl;
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