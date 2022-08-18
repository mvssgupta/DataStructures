#include <bits/stdc++.h>
using namespace std;

/// before knowing binary search
/// In general we perform linear search to find an element in an array
/// But it takes O(n) time complexity , where n is number of elements

/// Using binary search we can optimise this , iff the given array is sorted
/// we can reduce the time complexity from O(n) to O(log(n))

int linearSearch(vector<int> v, int searchKey)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == searchKey)
            return i;
    }
    return -1;
}


///intuition behind binary search:
/*
here in binary seach we are given an sorted array 
and we need to find an element whether it is present or not in the given array


In the code we have the start pointer and end pointer
we calculate the mid pointer and we compare the searchKey with that mid element

here we encounter three cases:
1:- If the element to be found is the mid element itself then we can return the mid index 
2:- If the element to be found is greater than the mid element 
then we will move the start pointer to (mid + 1) position , and continue doing binary search in the right part of mid element
3:- If the element to be found is lesser than the mid elemment
then we will move the end pointer to (mid-1) position and we will continue our search in left part of mid element


we perform the until only the start is less than or equal to end
Once the start crosses the end and move right side position to end then we need to stop 
and we have to return -1 , which indicates that the element we are searching for is not present in the given array
*/

int binarySearch(vector<int> v, int start, int end, int sKey)
{
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (v[mid] == sKey)
            return mid;
        else if (v[mid] < sKey)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int main()
{
    // vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    // int result = binarySearch(v,0,9,1);  //STATIC INPUT
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.emplace_back(k); // DYNAMIC INPUT
    }
    cout << "Enter the element to be found using linear search:";
    int skey2;
    cin >> skey2;
    int result1 = linearSearch(v, skey2);
    if (result1 != -1)
        cout << "Element found at : " << result1 << endl;
    else
        cout << "Element not found" << endl;
    cout << "Enter the element to be found using binary search:";
    int skey;
    cin >> skey;
    int result = binarySearch(v, 0, v.size() - 1, skey);
    if (result != -1)
        cout << "Element found at : " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}