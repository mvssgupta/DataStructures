#include<bits/stdc++.h>
using namespace std;
int binarySearch(int x){
    int start=1;
    int end=x;
    double mid;
    while(start<=end){
        mid=start + (end-start)/2;
        // here to avoid interger overflow for large numbers
        // instead of doinf mid*mid==x , we are doing mid==x/mid
        // double d = x/mid;
        if(mid==x/mid)  {
            return mid;
        }
        else if(mid>x/mid)
            end=mid-1;
        else
            start=mid+1;;
    }
    return end;
}
int main(){
    int n;cin>>n;
    int result= binarySearch(n);
    cout<<result<<endl;
    return 0;
}

