#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> nums, int k)
{
    deque<int> q;
    vector<int> res;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        while (!q.empty() && (nums[i] >= nums[q.back()]))
            q.pop_back();
        q.push_back(i);
        if (i - q.front() >= k)
            q.pop_front();
        if (i - k + 1 >= 0)
            res.push_back(nums[q.front()]);
    }
    return res;
}
