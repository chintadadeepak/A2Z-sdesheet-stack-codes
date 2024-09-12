#include <bits/stdc++.h>
using namespace std;

// intution is (sum of subarray maximums - sum of subarray minimums)

int sumSubarrayMins(vector<int> &arr)
{
    int size = arr.size();
    long long result = 0;
    int mod = (int)1e9 + 7;
    vector<int> nse(size);
    vector<int> pse(size);
    stack<pair<int, int>> st;
    stack<pair<int, int>> st1;
    nse[size - 1] = size;
    st.push({arr[size - 1], size - 1});
    for (int i = size - 2; i >= 0; i--)
    {
        if (st.top().first < arr[i])
            nse[i] = st.top().second;
        else
        {
            while (!st.empty() && st.top().first >= arr[i])
                st.pop();
            nse[i] = st.empty() ? size : st.top().second;
        }
        st.push({arr[i], i});
    }
    pse[0] = -1;
    st1.push({arr[0], 0});
    for (int i = 1; i < size; i++)
    {
        if (st1.top().first <= arr[i])
            pse[i] = st1.top().second;
        else
        {
            while (!st1.empty() && st1.top().first > arr[i])
                st1.pop();
            pse[i] = st1.empty() ? -1 : st1.top().second;
        }
        st1.push({arr[i], i});
    }
    for (int i = 0; i < size; i++)
        result = ((result + (((nse[i] - i) * 1LL * (i - pse[i]) % mod)) * 1LL * arr[i])) % mod;
    return result;
}