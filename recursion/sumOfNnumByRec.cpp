#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

/// here we can have two ways to calculate the
///  sum of N numbers from 1 to N using recursion

/// the two ways are : 1) parameterised way
///                    2) Functional way

//* parameterised way

/// it is called as parameterised way since
///  we are calculating the sum using parameters

void paramSum(int i, int sum)
{
    if (i < 1)
    {
        cout << "sum using parameterised way :- " << sum << endl;
        return;
    }
    paramSum(i - 1, sum + i);
}

//*functional way

/// here functional way means we have to return the sum
/// instead of printing the sum in the function itself

int funcSum(int n)
{
    if (n < 1)
        return 0;
    return n + funcSum(n - 1);
}

int factorial(int n)
{
    if(n<=1) return 1;
    return n*factorial(n-1);
}

int main()
{
    int n;
    cin >> n;
    /// here initially the sum is 0 , so we are passing 0 as one of the argument
    paramSum(n, 0);
    cout<<"sum using functional way :- "<<funcSum(n)<<endl;
    cout<<factorial(n)<<endl;
    return 0;
}