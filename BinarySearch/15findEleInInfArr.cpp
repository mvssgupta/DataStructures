#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

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


/*
Here the intution  is:-
since we dont know the end point or the length of the array 
first we have to take two variables start and end , initialised to 0 and 1 respectively

now we have to check whether our v[end] is less than the search key if so 
we have to change the start to end and end to end*2 .
which means we are changing the search area of the element.

while we get v[end] is greater than search key then we 
are ready to perform the normal binary search in the new start and end indices which
are calculated by us.
*/
int findEleInInfiniteSortedArr(vector<int>v,int sKey)
{
    int start = 0;
    int end=1;
    while(v[end]<sKey)
    {
        start=end;
        end=2*end;
    }
    return binarySearch(v,start,end,sKey);
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
        v.emplace_back(k); // DYNAMIC INPUT
    }
    
    //!while giving the search key we should give a number which is less than 
    //!the last element given in the input array,other wise we can get index out of bound error.
    cout << "Enter the element to be found :";
    int skey;
    cin >> skey;
    int result = findEleInInfiniteSortedArr(v, skey);
    if (result != -1)
        cout << "Element found at : " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}