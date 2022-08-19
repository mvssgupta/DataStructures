/*
Here we are given with a sorted array of characters , and we need to 
search for the next greater character for a given search character .

here there are three cases asusual :-

1:- here we are searching for next greater element , so if we got the element we are 
searching for we have to move the start pointer to mid+1 , since we are not searching the element 
given , rather we are searching for a greater element.

If the element given is last element we have to return the first element as answer
since we are searching in clockwise direction.

2:-If the element at mid is less than the search element then also we 
have to move the start pointer to mid+1 to search for the greater element
in the right part.

3:- In this third case the element at mid is greater than the element we are searching
now we have to store this element in a res variable , and we have to continue our search
in the left part of the mid,by moving the end pointer to mid-1.

though we got the element greater than the given element , we are doing search again,
why because we need to get the just next greater element for the given search key.
which means , the smallest element in the given array which is greater than search element.

*/

#include<bits/stdc++.h>
using namespace std;
char nextAlphabet(vector<char> v ,int start,int end, char sKey){
    int mid;
    char res='#';
    while(start<=end){
        mid = start + (end-start)/2;

        //here for the two cases
        //where v[mid]==skey and v[mid]<skey
        //we have to move start to mid+1 , so we can combine them as follows
        if(v[mid]<=sKey) start=mid+1;
        else {
            res=v[mid];
            end=mid-1;
        }
    }
    return (res!='#')?res:v[0];
}
int main(){
     vector<char> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        char k;
        cin>>k;
        v.emplace_back(k);              //DYNAMIC INPUT
    }
    cout<<"Enter the Alphabet to find its Next Alphabet:"; 
    char skey; 
    cin>>skey;
    char result = nextAlphabet(v,0,v.size()-1,skey);
    cout<<"Next Alphabet of "<<skey<<" is "<<result<<endl;
    return 0;
}



/*
we can solve this problem by using inbuilt function in stl
That is upper_bound... which gives us the next greater element

// auto result = upper_bound(v.begin(),v.end(),skey);
here we get the pointer pointing to the next greater element
if the pointer is pointing to the end of the vector it means, either it is the 
last element or the element we are searching is greater than the last element 
so we can print the first element of the vector as the next greater element.
since we are searching in clockwise , which means after the end element
we have to take the first element as next greater to end element.


    // if(result==v.end())
    //     cout<<v[0];
the result contains a pointer , to get the index of that element we have
to subtract the address of begin pointer of the vector
    // else
    //     cout<<v[result-v.begin()]<<endl;
*/