#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

void subSeqWhoseSumK(int i, vector<int> &v, int k, int sum, int arr[], int n)
{
    if (i == n)
    {
        if (sum == k)
        {
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
        }
        return;
    }

    //*take
    v.push_back(arr[i]);
    sum = sum + arr[i];
    subSeqWhoseSumK(i + 1, v, k, sum, arr, n);

    //*not take
    sum = sum - arr[i];
    v.pop_back();
    subSeqWhoseSumK(i + 1, v, k, sum, arr, n);
}

/// example :-
///  for {1,2,1} and sum=2
/// the pairs are {1,1} and {2}

///           {  1 ,  ___  ,  1 }  , {_____ , 2 , ______}
/// which are {take,not take,take} , {not take , take ,not take}

int main()
{
    int arr[] = {1, 2, 1};
    vector<int> v;
    v.clear();
    int n = sizeof(arr) / sizeof(arr[0]);
    subSeqWhoseSumK(0, v, 2, 0, arr, n);
    return 0;
}
