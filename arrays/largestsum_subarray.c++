//!brute force approach
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,max_sum=INT_MIN,st=0,end=0;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             if(sum>max_sum){
//                 max_sum=sum;
//                 st=i;
//                 end=j;
//             }
//             }
//     }
//     for(int i=st;i<=end;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<"\nmax sum:"<<max_sum<<endl;
//     return 0;
// }

//!using kaden's algorithm
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_sum=INT_MIN,curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum=curr_sum+arr[i];
        if(curr_sum>max_sum)
            max_sum=curr_sum;
        if(curr_sum<0)
            curr_sum=0;
    }
    cout<<"Max sum:"<<max_sum<<endl;
    return 0;
}

//sample input: arr = {-5,4,6,-3,4,-1}
//expected output: max sum: 11