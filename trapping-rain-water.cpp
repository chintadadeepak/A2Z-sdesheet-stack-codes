#include <bits/stdc++.h>
using namespace std;

// naive solution intuition ==> total += (leftMax, rightMax) - currentVal;

// optimal solution

int trap(vector<int> &nums)
{
    int res, leftMax, rightMax, left, right, size;
    res = left = 0;
    size = nums.size();
    leftMax = nums[0];
    rightMax = nums[size - 1];
    right = size - 1;
    while (left < right)
    {
        if (nums[left] < nums[right])
        {
            leftMax = max(leftMax, nums[left]);
            res += min(leftMax, nums[right]) - nums[left];
            left++;
        }
        else
        {
            rightMax = max(rightMax, nums[right]);
            res += min(rightMax, nums[left]) - nums[right];
            right--;
        }
    }
    return res;
}