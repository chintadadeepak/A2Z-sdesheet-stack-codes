#include <bits/stdc++.h>
using namespace std;

// naive solution -> arr[i] * (nse[i] - pse[i] - 1)
int largestRectangleArea(vector<int> &nums)
{
    vector<int> st;
    int size = nums.size();
    int area = INT_MIN;
    int currArea;
    int ind;
    for (int i = 0; i < size; i++)
    {
        if (st.empty() || nums[st.back()] < nums[i])
            st.push_back(i);
        else
        {
            while (!st.empty() && nums[st.back()] >= nums[i])
            {
                ind = st.back();
                st.pop_back();
                currArea = st.empty() ? nums[ind] * i : nums[ind] * (i - st[st.size() - 1] - 1);
                area = max(area, currArea);
            }
            st.push_back(i);
        }
    }
    for (int i = st.size() - 1; i >= 0; i--)
    {
        if (i == 0)
            area = max(area, nums[st[0]] * (size));
        else
            area = max(area, nums[st[i]] * (size - st[i - 1] - 1));
    }
    return area;
}