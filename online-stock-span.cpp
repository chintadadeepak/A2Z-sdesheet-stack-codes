#include <bits/stdc++.h>
using namespace std;

// problem is an extension of previous greatest element.

class StockSpanner
{
private:
    int cnt;
    stack<pair<int, int>> st;
    int answer;

public:
    StockSpanner()
    {
        cnt = 0;
        st.push({-1, -1});
    }

    int next(int price)
    {
        if (st.size() == 1 || st.top().first > price)
        {
            answer = cnt - st.top().second;
            st.push({price, cnt});
            cnt++;
            return answer;
        }
        while ((st.size() > 1) && price >= st.top().first)
            st.pop();
        answer = cnt - st.top().second;
        st.push({price, cnt});
        cnt++;
        return answer;
    }
};