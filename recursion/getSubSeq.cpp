#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl;

vector<string> subSeq(string &s)
{
    if(s.size()==0)
    {
        vector<string> res = {" "};      //if the string s's size is zero , return empty vector with empty string.
        return res;
    }
    char ch = s[0];                      
    string sub = s.substr(1);
    vector<string> recSubSeq = subSeq(sub);  //calling the rec for smaller input.

    vector<string> mainSubSeq;
    for(auto st:recSubSeq)
    {
        mainSubSeq.push_back(""+st);  //not taking the ch
        mainSubSeq.push_back(ch+st);  //taking the ch
    }
    return mainSubSeq;
}

int main()
{
    string s="abc";
    vector<string> res = subSeq(s);
    for(auto i:res)
    {
        cout<<i<<endl;
    }
    return 0;
}

//explanation :-

//expectation:- rec(abc) = ["","a","b","ab","c","ac","bc","abc"],
//faith:- rec(bc) = ["","b","c","bc"],
//relating the expectation and faith:-   rec(abc) =  ""+rec(bc)     ,  "a"+rec(bc).
//                                                         ^                ^
//                                                         |                |
//                                                  not taking 'a'   ,  taking 'a'