#include <bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int> &stones)
{
    if (stones.size() == 1)
        return stones[0];
    priority_queue<int> maxHeap;
    for (int i = 0; i < stones.size(); i++)
    {
        maxHeap.push(stones[i]);
    }
    while (maxHeap.size() > 1)
    {
        int y = maxHeap.top();
        maxHeap.pop();
        int x = maxHeap.top();
        maxHeap.pop();
        if (x == y)
            continue;
        else
            maxHeap.push(y - x);
    }
    if (maxHeap.size() == 0)
        return 0;
    else
        return maxHeap.top();
}
int main()
{
    vector<int> v = {2,7,4,1,8,1};
    cout << lastStoneWeight(v);
    return 0;
}
