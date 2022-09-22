#include <bits/stdc++.h>
using namespace std;

/*
the question is generating all the keycombinations when numbers are pressed.

for eg:- if we press 1 then we can get {"a","b","c"}
if we press 12 then combinations of 1 and 2 should be our ans , 
so ans = [ad  ae  af  bd  be  bf  cd  ce  cf]
*/

vector<string> keyPad = {"?!", "abc", "def", "ghi", "jkl", "mnop", "qrst", "uv", "wxyz", ".;"};
vector<string> rec(string num)
{
    if(num.size()==0) return {" "};  //base case
    char ch = num[0];                //extracting the first number
    string remNum = num.substr(1);
    vector<string> recRes = rec(remNum);  //faith => finding the solution for the remaining number
    vector<string> mainRes;
    string keyWordForch = keyPad[int(ch)-48];
    for(int i=0;i<keyWordForch.size();i++)  
    {
        char c = keyWordForch[i];
        for(auto r:recRes)
        {
            mainRes.push_back(c+r);    //building our final solution      
        }
    }
    return mainRes;
}
int main()
{
    int n;
    cout<<"Enter the number to get all the keyCombinations when we press them:- "
    cin >> n;
    vector<string> ans = rec(to_string(n));
    for (auto s : ans)
    {
        cout << s << " ";
    }
    return 0;
}


/*
for suppose n=125
then the possible combinations from {"abc","def","mnop"} are 
[adm  adn  ado  adp  aem  aen  aeo  aep  afm  afn  afo  afp  bdm  bdn  bdo  bdp  bem  ben  
beo  bep  bfm  bfn  bfo  bfp  cdm  cdn  cdo  cdp  cem  cen  ceo  cep  cfm  cfn  cfo  cfp]

we faith can be for 25{"def","mnop"} it will be[dm  dn  do  dp  em  en  eo  ep  fm  fn  fo  fp ]
then for 125 it would be 1*25=> "abc"*[dm  dn  do  dp  em  en  eo  ep  fm  fn  fo  fp ]
*/