#include<bits/stdc++.h>
using namespace std;
// char res='#';
// int binarySearch(vector<char> v ,int start,int end, char sKey){
//     int mid;
//     while(start<=end){
//         mid = start + (end-start)/2;
//         if(v[mid]==sKey)   start=mid+1;
//         else if(v[mid]<sKey) start = mid+1;
//         else {
//             res=v[mid];
//             end=mid-1;
//         }
//     }
//     return -1;
// }
int main(){
     vector<char> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        char k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    cout<<"Enter the Alphabet to find its Next Alphabet:"; 
    char skey; 
    cin>>skey;
    // int result = binarySearch(v,0,v.size()-1,skey);
    // if(result!=-1) cout<<"Next Alphabet of  "<<skey<<" is " <<v[result]<<endl;
    // else cout<<"Next Alphabet of "<<skey<<" is "<<res<<endl;
    auto result = upper_bound(v.begin(),v.end(),skey);
    if(result==v.end())
        cout<<v[0];
    else
        cout<<v[result-v.begin()]<<endl;
    return 0;
}