#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &nums)
{
    stack<int> st;
    int size = nums.size();
    vector<int> res(size, -1);
    res[0] = -1;
    st.push(nums[0]);
    for (int i = 1; i < size; i++)
    {
        if (!st.empty() && nums[i] > st.top())
            res[i] = st.top();
        else
        {
            while (!st.empty() && st.top() >= nums[i])
                st.pop();
            res[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[i]);
    }
    return res;
}
