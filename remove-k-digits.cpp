#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    vector<int> st;
    int size = num.size();
    string res;
    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && k && (st.back()) > (num[i] - '0'))
        {
            st.pop_back();
            k--;
        }
        st.push_back(num[i] - '0');
    }
    // removing extra digits from the end to meet the condition k
    while (k)
    {
        st.pop_back();
        k--;
    }
    int i = 0;
    // removing beginning zeroes
    while (i < st.size() && st[i] == 0)
        i++;
    if (i == st.size())
        return "0";
    for (; i < st.size(); i++)
        res.push_back(st[i] + '0');
    if (res.empty())
        return "";
    return res;
}

// need to cover two more edge cases
// string removeKdigits(string num, int k)
// {
//     // first edge case
//     if (num.size() == k)
//         return "0";
//     vector<int> st;
//     int size = num.size();
//     int flag = 0;
//     int i;
//     int initK = k;
//     int initZeroes = 0;
//     string res = "";
//     for (i = 0; i < size;)
//     {
//         if (st.empty() || st.back() <= (num[i] - '0'))
//         {
//             st.push_back(num[i] - '0');
//             i++;
//         }
//         else
//         {
//             if (st.empty() && num[i] == '0')
//                 continue;
//             while (!st.empty() && st.back() > (num[i] - '0'))
//             {
//                 st.pop_back();
//                 k--;
//                 if (k == 0)
//                 {
//                     flag = 1;
//                     break;
//                 }
//             }
//             st.push_back(num[i] - '0');
//             i++;
//         }
//         if (flag)
//             break;
//     }
//     for (; i < size; i++)
//         st.push_back(num[i] - '0');
//     // third edge case removing extra numbers from the end
//     while (!st.empty() && (st.size() != num.size() - initK))
//         st.pop_back();
//     for (i = 0; i < st.size(); i++)
//         res.push_back(st[i] + '0');
//     return res;
// }

// int main()
// {
//     cout << removeKdigits("1432219", 3);
// }