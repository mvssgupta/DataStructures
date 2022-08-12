#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;


/// here we have to print only unique combinations
///the input array may contain duplicate elements but 
/// we have to take an element only once...

///for example : arr = {10, 1, 2, 7, 6, 1, 5} , K=8  here 1 is repeated twice 
///In general the combinations are :-             |
/*                                             
/   1 2 5                                         |  the actual combinations we need to get are :- 
/   1 7                                           |                                       1 1 6 
/   1 6 1                                         |                                       1 2 5
/   2 6                                           |                                       1 7
/   2 1 5                                         |                                       2 6
/   7 1                                           |                                       
*/ ///but here we can observe that {1,2,5} and {2,1,5} are same , so we have to 
///eliminate them , since they are duplicate combinations

///so initially we have to sort the array and then perform the operations
///and also while doing the operations we have to take care of duplicate combinations.



void combinationSum(int ind, vector<int> &v, int k, int arr[], int n)
{
    if (k == 0)
    {

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
        return;
    }
    for (int i = ind; i < n; i++)
    {
        ///here we are checking whether arr[i] and arr[i-1] are same or not
        /// if same we have to skip , why because while considering the previous element
        ///we already get a comination , since the next element is also same , we will get
        ///an duplicate combination that's why we have to skip that element.
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        ///if the arr[i]>k we have to skip that element why because it can't be include in
        ///our combination , since we need an small element which satisfies our condition
        if (arr[i] > k)
            break;

        v.push_back(arr[i]);
        combinationSum(i + 1, v, k - arr[i], arr, n);
        v.pop_back();
    }
}

int main()
{
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    sort(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    vector<int> v;
    combinationSum(0, v, 8, arr, *(&arr + 1) - arr);
    return 0;
}
