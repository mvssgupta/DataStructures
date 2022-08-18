//* i) first and last occurence of an element
//* ii) count of an element

/*
Here we need to find whether an element is present or not and
if present we have to return its first occurrence and last occurrence
in the array.


here the intuition is we have to search for an element in the
given array , when we got that element we should not stop the
search there , we should continue the search by storing the current index value.
Finally we have to return a value ,
1:- the value is -1 if the element is not found in the array
2:- otherwise the value is the first and last occurrence of the element in the given array.

*/
#include <bits/stdc++.h>
using namespace std;
int firstbinarySearch(vector<int> v, int start, int end, int sKey)
{
    int mid, firstOccur = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (v[mid] == sKey)
        {
            /// here although we got the element , we are continuing the search
            /// to check for furthur matches, if furthur any match occur then it
            /// means previous match is not the first occurrence , so we return next matched index as our answer.
            firstOccur = mid;
            end = mid - 1;
        }
        else if (v[mid] < sKey)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return firstOccur;
}
int lastbinarySearch(vector<int> v, int start, int end, int sKey)
{
    int mid, lastOccur = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (v[mid] == sKey)
        {
            /// here although we got the element , we are continuing the search
            /// to check for furthur matches, if furthur any match occur then it
            /// means previous match is not the last occurrence , so we return next matched index as our answer.
            lastOccur = mid;
            start = mid + 1;
        }
        else if (v[mid] < sKey)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return lastOccur;
}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.emplace_back(k);
    }
    cout << "Enter the element to be found:";
    int skey;
    cin >> skey;
    int result1 = firstbinarySearch(v, 0, v.size() - 1, skey);
    int result2 = lastbinarySearch(v, 0, v.size() - 1, skey);
    if (result1 != -1)
    {
        cout << "1st Occurence of Element found at : " << result1 << endl;
    }
    if (result2 != -1)
    {
        cout << "Last Occurence of Element found at : " << result2 << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    cout << "Count of " << skey << " is " << result2 - result1 + 1 << endl;
    return 0;
}