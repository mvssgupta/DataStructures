#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

//?brute force approach
vector<int> firstNegativeNumber1(vector<int> &v, int k)
{
    vector<int> ans;
    for (int i = 0; i < v.size() - k + 1; i++)
    { // 12,-1,-7,8,-15,30,16,28
        int flag = 0;
        for (int j = i; j < i + k; j++)
        {
            if (v[j] < 0)
            {
                ans.push_back(v[j]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            ans.push_back(0);
    }
    return ans;
}

//?sliding window approach
vector<int> firstNegativeNumber2(vector<int> &A, int K)
{
    int N = A.size();
    int i=0;
    int j=0;
    vector<int> ans;
    list<int> l;
    while (j < N)
    {
        if (A[j] < 0)
            l.push_back(A[j]);
        if (j - i + 1 < K)
            j++;
        else if ((j - i + 1) == K)
        {
            if (l.size() == 0)
                ans.push_back(0);
            else
                ans.push_back(l.front());
            if (A[i] == l.front())
                l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {12, -1, -7, 8, -15, 30, 16, 28};
    vector<int> ans = firstNegativeNumber2(A, 3);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}