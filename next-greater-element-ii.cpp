// doubling the array will make the problem super simple.

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    int size = nums.size();
    vector<int> res(size, -1);
    st.push(nums[size - 1]);
    for (int i = size - 2; i >= 0; i--)
    {
        while (!st.empty() && nums[i] >= st.top())
            st.pop();
        st.push(nums[i]);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        if (!st.empty() && nums[i] < st.top())
            res[i] = st.top();
        else
        {
            while (!st.empty() && nums[i] >= st.top())
                st.pop();
            res[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[i]);
    }
}