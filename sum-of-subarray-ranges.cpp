#include <bits/stdc++.h>
using namespace std;

long long subArrayMaxs(vector<int> &arr)
{
    int size = arr.size();
    long long result = 0;
    vector<int> nge(size);
    vector<int> pge(size);
    stack<pair<int, int>> st;
    stack<pair<int, int>> st1;
    nge[size - 1] = size;
    st.push({arr[size - 1], size - 1});
    for (int i = size - 2; i >= 0; i--)
    {
        if (st.top().first > arr[i])
            nge[i] = st.top().second;
        else
        {
            while (!st.empty() && arr[i] >= st.top().first)
                st.pop();
            nge[i] = st.empty() ? size : st.top().second;
        }
        st.push({arr[i], i});
    }
    pge[0] = -1;
    st1.push({arr[0], 0});
    for (int i = 1; i < size; i++)
    {
        if (st1.top().first >= arr[i])
            pge[i] = st1.top().second;
        else
        {
            while (!st1.empty() && arr[i] > st1.top().first)
                st1.pop();
            pge[i] = st1.empty() ? -1 : st1.top().second;
        }
        st1.push({arr[i], i});
    }
    for (int i = 0; i < size; i++)
        result = result + (nge[i] - i) * 1LL * (i - pge[i]) * 1LL * arr[i];
    return result;
}

long long subArrayMins(vector<int> &arr)
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
        result = result + (nse[i] - i) * 1LL * (i - pse[i]) * 1LL * arr[i];
    return result;
}

long long subArrayRanges(vector<int> &nums)
{
    return subArrayMaxs(nums) - subArrayMins(nums);
}
