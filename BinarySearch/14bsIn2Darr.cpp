#include<bits/stdc++.h>
using namespace std;
pair<int,int> binarySearchIn2DArr( vector< vector<int> > v,int n,int m,int sKey){
    pair<int,int> p;
    int i=0,j=m-1;
    while( (i>=0&&i<n ) && (j>=0&&j<m)){
        if(v[i][j]==sKey){
            p.first = i;
            p.second = j;
            return p;
        } 
        else if(v[i][j]<sKey){
            i++;
        }
        else if(v[i][j]>sKey){
            j--;
        }
    }
    return {-1,-1};
}
int main(){
    vector< vector<int> > v = 
    {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };
    pair<int,int> result = binarySearchIn2DArr(v,4,4,49);
    if(result.first!=-1) cout<<"Key found at : "<<result.first<<" "<<result.second<<" location"<<endl;
    else cout<<"Element not found in the given 2D vector."<<endl;
    return 0;
}