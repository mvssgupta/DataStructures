#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

///instead of swapping the elements iteratively
///we are swapping the corner elements and then recursively
/// calling this function by incrementing the start pointer(lft) 
///and by decrementing the last pointer(rgt)

void reverseArray(int lft, int rgt, int arr[])
{
    if (lft > rgt)
        return;
    
    /// here we are post incrementing and decrementing the pointers itself
    ///in other way we can just pass the pointers lft and rgt and then while
    ///calling recursively we can increment and decrement them in function parameters itself
    ///swap(arr[lft],swap[rgt]);
    ///reverseArray(lft+1,rgt-1);

    swap(arr[lft++], arr[rgt--]); 
    reverseArray(lft, rgt, arr);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    reverseArray(0, 4, arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}