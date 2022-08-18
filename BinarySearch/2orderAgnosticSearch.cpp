//!  credits: geeksforgeeks


/*
this is order agnostic search which means 
we dont know whether the sorted arrary is sorted in ascending or descending order

In both ascending or descending the first case is same
which is , if the element at mid matches the search element , simply we return the index of mid

for the remaining two cases the searching process changes as follows

Incase of ascending order:- 
the scenarios are :-
	case-1:-If the search element is smaller than mid element 
	then we have to move the end to (mid-1) position and continue our search
	case-2:-If the search element is greater than mid element then 
	we have to move our start pointer to (mid+1) position and continue the search

Incase of descending order:- 
the scenarios are :-
	case-1:-If the search element is smaller than mid element 
	then we have to move the start pointer to (mid+1) position and continue our search
	case-2:-If the search element is greater than mid element then 
	we have to move our end to (mid-1) position and continue the search


If we dont find the element then we have to return -1 , which indicates that the element is not found
*/


#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int start, int end, int x)
{
	bool isAsc = arr[start] < arr[end];
	while (start <= end) {
		int middle = start + (end - start) / 2;
		if (arr[middle] == x)
			return middle;
		if (isAsc == true) {
			if (arr[middle] < x)
				start = middle + 1;
			else
				end = middle - 1;
		}
		else {
			if (arr[middle] > x)
				start = middle + 1;
			else
				end = middle - 1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 40, 10, 5, 2, 1 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << binarySearch(arr, 0, n - 1, x);

	return 0;
}

