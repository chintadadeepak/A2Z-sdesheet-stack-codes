#include <bits/stdc++.h>
using namespace std;
// celebrity mean everyone knows him/her, but he/she dont know others...

int celebrity(vector<vector<int>> &mat)
{
    int size = mat.size();
    int top = 0;
    int bottom = size - 1;
    while (top < bottom)
    {
        if (mat[top][bottom] == 0 && mat[bottom][top] == 0)
        {
            top++;
            bottom--;
            continue;
        }
        if (mat[top][bottom])
            top++;
        if (mat[bottom][top])
            bottom--;
    }
    if (bottom > top)
        return -1;
    // verifying for safe side
    for (int i = 0; i < size; i++)
    {
        if (mat[top][i])
            return -1;
    }
    for (int i = 0; i < size; i++)
    {
        if (i == top)
            continue;
        if (mat[i][top] == 0)
            return -1;
    }
    return top;
}