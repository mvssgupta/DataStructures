#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

int countSubSeqWhoseSumK(int i, int k, int sum, int arr[], int n)
{
    if (i == n)
    {
        if (sum == k)
            return 1;
        return 0;
    }

    //*take
    sum = sum + arr[i];
    int take = countSubSeqWhoseSumK(i + 1, k, sum, arr, n);

    //*not take
    sum = sum - arr[i];
    int notTake = countSubSeqWhoseSumK(i + 1, k, sum, arr, n);

    return take + notTake;
}

/// example :-
///  for {1,2,1} and sum=2
/// the pairs are {1,1} and {2}

///           {  1 ,  ___  ,  1 }  , {_____ , 2 , ______}
/// which are {take,not take,take} , {not take , take ,not take}
int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = countSubSeqWhoseSumK(0, 2, 0, arr, n);
    cout << "The count of subsequences in the given array whose sum is 2 is " << res << endl;
    return 0;
}
