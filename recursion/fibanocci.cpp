#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int main()
{

    int n;
    cout<<"Enter N to get Nth fibanocci number : ";
    cin >> n;
    cout <<n<<"th Fibanocci number is : "<<fib(n) << endl;
    return 0;
}