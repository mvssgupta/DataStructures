#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    // vector<int> v;
    //     while(n){
    //         v.push_back(n%10);
    //         n/=10;
    //     }
    //            reverse(v.begin(),v.end());
    // for(auto c:v){
    //     cout<<c<<" ";
    // }
      vector<int> v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        int i=v.size()-1;
        while(i>0 && v[i]<v[i-1]){
            i--;
        }
        i--;
        if(i==-1) return -1; 
        vector<int> v2 = v;
        sort(v2.begin()+i,v2.end());
        int nGtoSmall = *upper_bound(v2.begin()+i+1,v2.end(),v[i]);
        // cout<<"nge:"<<nGtoSmall<<endl;
        int index = find(v.begin(),v.end(),nGtoSmall)-v.begin();
        swap(v[i],v[index]);    //! error
        sort(v.begin()+i+1,v.end());
        // for(auto c:v){
        //     cout<<c;
        // }
        string str="";
        for(int i=0;i<v.size();i++){
            str += to_string(v[i]);
        }
    // return stoi(str);
    // cout<<stoi(str);
    if(stoi(str)>n && stoi(str)<2,147,483,647) return stoi(str);
    else return -1;
    return 0;
}



















// https://leetcode.com/problems/next-greater-element-iii/discuss/766616/C%2B%2B-stack-implementation-or-0-ms-or-6.1-MB





// class Solution {
// public:
//     int nextGreaterElement(int n) {
//         vector<int> v;
//         while(n){
//             v.push_back(n%10);
//             n/=10;
//         }
//         reverse(v.begin(),v.end());
//         int i=v.size()-1;
//         while(i>0 && v[i]<v[i-1]){
//             i--;
//         }
//         i--;
//         if(i==-1) return -1; 
//         vector<int> v2 = v;
//         sort(v2.begin()+i,v2.end());
//         int nGtoSmall = *upper_bound(v2.begin()+i+1,v2.end(),v[i]);
//         int index = find(v.begin(),v.end(),nGtoSmall)-v.begin();
//         swap(v[i],v[index]);  
//         sort(v.begin()+i+1,v.end());
//         string str="";
//         for(int i=0;i<v.size();i++){
//             str += to_string(v[i]);
//         }
//     // if(stoi(str)>n) return stoi(str);
//         long ans = stoi(str);
//         if(ans>n) return ans;
//         else return -1;
//     }
// };