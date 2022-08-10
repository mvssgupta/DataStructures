#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

void PrintNameNtimes(int n, string name)
{
    if (n == 0)
        return;
    cout << name << endl;
    PrintNameNtimes(--n, name);
}

void PrintLinearlyFrom1toN(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    /// here we are using i=i+1 to incrementing i for furthur calls
    PrintLinearlyFrom1toN(i + 1, n);
}

void PrintLinearlyFromNto1(int i, int n)
{
    if (i < 1)
        return;
    cout << i << endl;
    /// here we are using i=i-1 to decrementing i for furthur calls
    PrintLinearlyFromNto1(i - 1, n);
}

void PrintLinearlyFrom1toNUsingBackTracking(int i, int n)
{
    /// here we should use i=i-1 to print 1 to N
    /// here initially we intialise i to n and then we decrement it
    if (i < 1)
        return;
    PrintLinearlyFrom1toNUsingBackTracking(i - 1, n);
    cout << i << endl;
}

void PrintLinearlyFromNto1UsingBackTracking(int i, int n)
{
    /// here we should use i=i+1 to print N to 1
    /// here initially we intialise i to n and then we decrement it
    if (i > n)
        return;
    PrintLinearlyFromNto1UsingBackTracking(i + 1, n);
    cout << i << endl;
}

int main()
{
    int n, i = 1;
    string s;
    cin >> n;
    cin >> s;
    cout << "Printing the name : " << s << " " << n << " times:-" << endl;
    PrintNameNtimes(n, s);
    cout<<"Printing the numbers from 1 to "<<n<<" :-"<<endl;
    PrintLinearlyFrom1toN(i, n);
    cout<<"Printing the numbers from "<<n<<" to 1:-"<<endl;
    PrintLinearlyFromNto1(n, n);
    cout<<"Printing the numbers from 1 to "<<n<<" by using BackTracking:-"<<endl;
    PrintLinearlyFrom1toNUsingBackTracking(n, n);
    cout<<"Printing the numbers from "<<n<<" to 1 by using BackTracking:-"<<endl;
    PrintLinearlyFromNto1UsingBackTracking(i, n);
    return 0;
}