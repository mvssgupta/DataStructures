#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

/// It is same as finding the subsequences but here
/// we are asked to print only one subsequene which
/// satisifies the given condition , instead of all subsequences

///for only printing one subsequence we can have an global variable like flag
/// and by changing it to false and then we can stop furthur recursion , which is 
///called as parameterised way. 
bool flag = true;
Poid paramsubSeqWhoseSumK(int i, vector<int> &v, int k, int sum, int arr[], int n)
{
    if (i == n)
    {
        if (sum == k && flag)
        {
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
            flag=false;
        }
        return;
    }

    //*take
    v.push_back(arr[i]);
    sum = sum + arr[i];
    ParamsubSeqWhoseSumK(i + 1, v, k, sum, arr, n);

    //*not take
    sum = sum - arr[i];
    v.pop_back();
    ParamsubSeqWhoseSumK(i + 1, v, k, sum, arr, n);
}



///we can also do it by using functional way which means we have to return
///something from a function instead of passing a parameter and checking
///here we are returning true if we got the answer and stopping the other recursion calls
bool funsubSeqWhoseSumK(int i, vector<int> &v, int k, int sum, int arr[], int n)
{
    if (i == n)
    {
        if (sum == k)
        {
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    //*take
    v.push_back(arr[i]);
    sum = sum + arr[i];
    ///if we get an answer we have to return true
    ///if we get false then we have to goto not take conditon also.
    if (subSeqWhoseSumK(i + 1, v, k, sum, arr, n))
        return true;

    //*not take
    sum = sum - arr[i];
    v.pop_back();

    ///here also same , if we get the answer then also we should return true
    if (subSeqWhoseSumK(i + 1, v, k, sum, arr, n))
        return true;
    return false;
}

/// example :-
///  for {1,2,1} and sum=2
/// the pairs are {1,1} and {2}

///           {  1 ,  ___  ,  1 }  , {_____ , 2 , ______}
/// which are {take,not take,take} , {not take , take ,not take}


//*BOTH FUNCTIONAL AND PARAMETERISED WAYS ARE CORRECT
//*WE CAN USE ANY OFF THEM.     
int main()
{
    int arr[] = {1, 2, 1};
    vector<int> v;
    v.clear();
    int n = sizeof(arr) / sizeof(arr[0]);
    ParamsubSeqWhoseSumK(0, v, 2, 0, arr, n);
    return 0;
}
