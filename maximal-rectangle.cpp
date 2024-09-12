#include <bits/stdc++.h>
using namespace std;

// logic is, this problem is an extension to largest rectangle in histogram.

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

int maximalRectangle(vector<vector<char>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int area = INT_MIN;
    vector<int> curr(n, 0);
    for (int j = 0; j < n; j++)
        curr[j] = mat[0][j] - '0';
    area = max(area, largestRectangleArea(curr));
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == '0')
                curr[j] = 0;
            else
                curr[j] += mat[i][j] - '0';
        }
        area = max(area, largestRectangleArea(curr));
    }
    return area;
}