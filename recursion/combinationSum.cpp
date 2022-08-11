#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;


///the question is we have to find the subsequence whose sum is K
///and here we can take any element any number of times

void subSeqWhoseSumK(int i, vector<int> &v, int k, int arr[], int n)
{
    if (i == n)
    {
        if (k == 0)
        {
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
        }
        return;
    }

    //*take multiple times if possible
    ///in this case , if we are considering an element 
    ///we can decrement the required value by the element taken
    ///which means the target value should decrease by arr[i](such that K = K-arr[i])
    if (arr[i] <= k)
    {
        v.push_back(arr[i]);
        subSeqWhoseSumK(i, v, k - arr[i], arr, n);
        v.pop_back();
    }

    //*not take
    ///if we don't want to take furthur then we can move to next index
    subSeqWhoseSumK(i + 1, v, k, arr, n);
}

/// example :-
///  for {2, 3, 6, 7 and sum=7
/// here we are allowed to take an element multiple times
/// the pairs are {2,2,3} and {7}

int main()
{
    int arr[] = {2, 3, 6, 7};
    vector<int> v;
    v.clear();
    int n = sizeof(arr) / sizeof(arr[0]);
    subSeqWhoseSumK(0, v, 7, arr, n);
    return 0;
}
