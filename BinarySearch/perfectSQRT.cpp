#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int x) {
    int start=1;
    int end=x;
    double mid;
    while(start<=end){
        mid=start + (end-start)/2;
        // here to avoid interger overflow for large numbers
        // instead of doinf mid*mid==x , we are doing mid==x/mid
        if(mid==x/mid)  
            return true;
        else if(mid>x/mid)
            end=mid-1;
        else
            start=mid+1;
    }
    return false;
}


int main(){
    cout<<"Enter a number to check whether it is perfect square or not: ";
    int n;cin>>n;
    cout<<isPerfectSquare(n)<<endl;;
    return 0;
}
 