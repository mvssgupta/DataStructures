#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;
double myPow(double x, int n) {
    if(n<0){
        x=1/x;
        n=abs(n);
    }
    if(n==0) return 1;
    //Intution is x^4 = x^2*x^2. It gives logarithmic time complexity , if we do x*x*x*x for x^4 then we will get TLE.
    double ans = myPow(x,n/2);

    //explanation of below line of code , let x^5 then we have to do x*x^2*x^2 , if x^4 then it will be x^2*x^2.
    return (n%2==0)?(ans*ans):(x*ans*ans);    
}
                                   
int main()
{
    int x,n;
    cout<<"Enter the values of  X and N :";
    cin>>x>>n;
    cout<<"The value of "<<x<<" raised to "<<n<<" is "<<myPow(x,n);
    return 0;
}