#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

void rec(vector<int> &v , int ind)                               
{
    if(ind==v.size()) return;
    cout<<v[ind++]<<" ";
    rec(v,ind);
}
int main()
{
    vector<int> v={1,2,3,4,5};
    rec(v,0);
    return 0;
}