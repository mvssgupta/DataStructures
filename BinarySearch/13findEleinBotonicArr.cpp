#include<bits/stdc++.h>
using namespace std;
int maxElementIndex(vector<int> v ,int start,int end){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(mid>0 && mid<v.size()-1) {
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1])
                return mid;
            else if(v[mid-1]>v[mid])
                end=mid-1;
            else 
                start=mid+1;
        }
        else if(mid==0){
            if(v[mid]>v[mid+1])
                return mid;
            return mid+1;
        }
        else if(mid==v.size()-1){
            if(v[mid]>v[mid-1])
                return mid;
            return mid-1;
        }
    }
    return 0;
}

int IncbinarySearch(vector<int> arr, int start, int end, int x)
{
	while (start <= end) {
		int middle = start + (end - start) / 2;
		if (arr[middle] == x)
			return middle;
        if (arr[middle] < x)
            start = middle + 1;
        else
            end = middle - 1;
	}
	return -1;
}

int DscbinarySearch(vector<int> arr, int start, int end, int x)
{
	while (start <= end) {
		int middle = start + (end - start) / 2;
		if (arr[middle] == x)
			return middle;
        if (arr[middle] > x)
            start = middle + 1;
        else
            end = middle - 1;
	}
	return -1;
}

int main(){
     vector<int> v;
    int n; cin>>n;
    cout<<"Enter the elements of Bitonic Array:"<<endl;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    cout<<"Enter element to be search :";
    int sKey;cin>>sKey;
    int index = maxElementIndex(v,0,v.size()-1);
    int res1 = IncbinarySearch(v,0,index-1,sKey);
    int res2 = DscbinarySearch(v,index,v.size()-1,sKey);
    int result = max(res1,res2);
    if(result!=-1)
        cout<<"Element found at index: "<<result<<endl;
    else 
        cout<<"Element not found"<<endl;
    return 0;
}

