#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                else if (s[i] == ')')
                {
                    if (st.top() != '(')
                        return false;
                    st.pop();
                }
                else if (s[i] == ']')
                {
                    if (st.top() != '[')
                        return false;
                    st.pop();
                }
                else
                {
                    if (st.top() != '{')
                        return false;
                    st.pop();
                }
            }
        }
        return st.size() == 0;
    }
};