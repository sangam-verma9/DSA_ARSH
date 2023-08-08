#include <bits/stdc++.h>
using namespace std;
// optimized aproach here we use first row and col as a array store to further set to zero.
//************* TC: O(N+M) SC: O(1)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag1 = 0, flag2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
            {
                flag1 = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == 0)
            {
                flag2 = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag1 == 1)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
        if (flag2 == 1)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
};
/********/
// my first approach tc: O(N*M) sc: O(N+M)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row;
        vector<int> col;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (find(row.begin(), row.end(), i) != row.end())
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }

            for (int j = 0; j < m; j++)
            {
                if (find(col.begin(), col.end(), j) != col.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
//***********

int main()
{

    return 0;
}
