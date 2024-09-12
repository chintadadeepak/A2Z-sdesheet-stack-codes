#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &nums)
{
    vector<int> st;
    int flag;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (st.empty() || nums[i] > 0)
            st.push_back(nums[i]);
        else
        {
            if ((st.back() < 0 && nums[i] < 0) || (st.back() < 0 && nums[i] > 0))
            {
                st.push_back(nums[i]);
                continue;
            }
            flag = 0;
            while (!st.empty() && abs(nums[i]) >= st.back())
            {
                if (abs(nums[i]) == st.back())
                {
                    st.pop_back();
                    break;
                }
                else if (abs(nums[i]) > st.back())
                {
                    st.pop_back();
                    if (!st.empty() && st.back() < 0)
                    {
                        st.push_back(nums[i]);
                        break;
                    }
                }
                if (st.empty())
                    flag = 1;
            }
            if (flag)
                st.push_back(nums[i]);
        }
    }
    return st;
}

// int main()
// {
//     vector<int> nums = {-2, -1, 1, 2};
//     vector<int> res = asteriodCollision(nums);
//     for (int i : res)
//         cout << i << " ";
// }
