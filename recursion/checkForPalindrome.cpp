#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

bool checkForPalindrome(int st, int len, string s)
{
    if (st > len / 2)
        return true;
    bool val = s[st] == s[len];
    return val && checkForPalindrome(st + 1, len - 1, s);
}

/// we can also write the logic as
///if(st>len/2) return true;
/// if(s[st]!=s[len]) return false;
/// return checkForPalindrome(st+1,len-1,s);

int main()
{
    string s;
    cout << "Enter a string to check whether it is palindrome or not : ";
    cin >> s;
    bool val = checkForPalindrome(0, s.size() - 1, s);
    (val) ? cout << "Palindrome\n" : cout << "Not a Palindrome\n";
    return 0;
}