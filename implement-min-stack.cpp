#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    long long prev_min = INT_MAX;
    stack<long long> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            prev_min = min((int)prev_min, val);
        }
        else
        {
            if (val < prev_min)
            {
                st.push(2 * 1LL * val - prev_min);
                prev_min = val;
            }
            else
                st.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        else if (st.top() >= prev_min)
            st.pop();
        else
        {
            prev_min = 2 * 1LL * prev_min - st.top();
            st.pop();
        }
        if (st.empty())
            prev_min = INT_MAX;
    }

    int top()
    {
        return st.top() > prev_min ? (int)st.top() : (int)prev_min;
    }

    int getMin()
    {
        return (int)prev_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */