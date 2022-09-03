#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

//rotating the array in clockwise

//time complexity : O(arr.size()*n) where n is number of elements need to be rotated
//In worst case the n can be the size of the array then the timecomplexity is O(v.size()^2)

vector<int> rotateArray(vector<int> &v,int n)
{
    while(n--)
    {
        int last = v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--)
        {
            v[i+1]=v[i];
        }
        v[0] = last;
    }
    return v;
}

int main()
{
    vector<int> v = {3,2,1,5,7,8};
    cout<<"Before rotation : ";
    for(auto i:v)
    {
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Enter the number of times the array need to be rotated : ";
    int n;
    cin>>n;
    v = rotateArray(v,n);
    cout<<"After rotation : ";
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}