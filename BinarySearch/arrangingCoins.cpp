#include<bits/stdc++.h>
using namespace std;
int arrangeCoins(int n) {
    long int start=1,end=n;
        while(start<=end){
           long int mid= start + (end-start)/2;
           long int value = mid*(mid+1)/2;
            if(value==n)
                return int(mid);
            if(value<n)
                start = mid+1;
            else
                end = mid-1;
        }
        return int(end);
}
int main(){
    int n;
    cin>>n;
    cout<<arrangeCoins(n)<<endl;
    return 0;
}