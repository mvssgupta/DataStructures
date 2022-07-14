#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> v ,int start,int end, int sKey){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(v[mid]==sKey)   return mid;
        else if(v[mid]<sKey)  start = mid+1;
        else  end=mid-1;
    }
    return start;
}
int main(){
    vector<int> v = {1,3,5,6,7,8,10};
    // int result = binarySearch(v,0,6,9);  //STATIC INPUT
    //  vector<int> v;
    // int n; cin>>n;
    // for(int i=0;i<n;i++){
    //     int k;
    //     cin>>k;
    //     v.emplace_back(k);              //DYNAMIC INPUT
    // }
    cout<<"Enter the element to be found:"; int skey; cin>>skey;
    int result = binarySearch(v,0,v.size()-1,skey);
    cout<<"Insertion position of "<<skey<<" is "<<result<<endl;
    return 0;
}






// //! using lower_bound function
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> v = {1,3,6,8,10,15};
//     //lower_bound will return the element if present , otherwise it will return 
//     // the element greater than that.
//     //here it is asked to return the index.
//     // so to get the index we can subtract the starting address
//     // of the given vector from the result of lower_bound function
//     int result = lower_bound(v.begin(),v.end(),9) - v.begin();  //STATIC INPUT
//     cout<<result<<endl;
//     return 0;
// }