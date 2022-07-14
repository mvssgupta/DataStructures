#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

//?brute force approach
int maxSumSubArr1(vector<int> &v, int k)
{
    int vSize = v.size();
    int maxSum = 0;
    for (int i = 0; i < vSize; i++)
    {
        int currSum = 0;
        for (int j = i; j < i + k; j++)
        {
            currSum += v[j];
        }
        if (currSum > maxSum)
            maxSum = currSum;
    }
    return maxSum;
}

//?sliding window approach
int maxSumSubArr2(vector<int> &v, int k)
{
    int vSize = v.size();
    int currSum = 0;
    for (int i = 0; i < k; i++)
    {
        currSum += v[i];
    }
    int maxSum = currSum;
    for (int i = k; i < vSize; i++)
    {
        currSum = currSum + v[i] - v[i - k];
        if (currSum > maxSum)
            maxSum = currSum;
    }
    return maxSum;
}

// Time Complexity : O(n)
// Auxiliary Space : O(1)
class Solution
{
public:
    int maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        int i = 0;
        int j = 0;
        int sum = 0;
        int mx = INT_MIN;
        while (j < N)
        {
            sum = sum + Arr[j]; // do calculation to reduse tc
            if (j - i + 1 < K)
                j++;                   // increament j upto when the size of the size of window is not equal to required size
            else if ((j - i + 1) == K) // when sindow size hit to the required window size
            {
                mx = max(mx, sum);  // selecting ans from the candidates
                sum = sum - Arr[i]; // start removing from the first
                i++;
                j++;
            }
        }
        return mx;
    }
};

int main()
{
    vector<int> v = {7, 4, 5, 8, 8, 3, 9, 8, 7, 6};
    int n, k;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    cout << "Enter the value of K: ";
    cin >> k;
    cout << "Result: " << maxSumSubArr2(v, k) << endl;
    return 0;
}