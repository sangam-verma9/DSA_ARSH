#include <bits/stdc++.h>
using namespace std;
//****** my approcah TC: O(N^2) SC:O(N^2)
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cnt = 0;
                if (i + 1 < m)
                {
                    if (board[i + 1][j] == 1)
                        cnt++;
                }
                if (i - 1 >= 0)
                {
                    if (board[i - 1][j] == 1)
                        cnt++;
                }
                if (j + 1 < n)
                {
                    if (board[i][j + 1] == 1)
                        cnt++;
                }
                if (j - 1 >= 0)
                {
                    if (board[i][j - 1] == 1)
                        cnt++;
                }
                if (j + 1 < n && i + 1 < m)
                {
                    if (board[i + 1][j + 1] == 1)
                        cnt++;
                }
                if (j - 1 >= 0 && i - 1 >= 0)
                {
                    if (board[i - 1][j - 1] == 1)
                        cnt++;
                }
                if (i + 1 < m && j - 1 >= 0)
                {
                    if (board[i + 1][j - 1] == 1)
                        cnt++;
                }
                if (j + 1 < n && i - 1 >= 0)
                {
                    if (board[i - 1][j + 1] == 1)
                        cnt++;
                }
                if (board[i][j] == 1)
                {
                    if (cnt < 2)
                        v[i][j] = 0;
                    else if (cnt == 2 || cnt == 3)
                        v[i][j] = 1;
                    else if (cnt > 3)
                        v[i][j] = 0;
                }
                else
                {
                    if (cnt == 3)
                        v[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = v[i][j];
            }
        }
    }
};
//*********
// In second approch we can create arrays of dx and dy and then traverse to them idea is same only heip in less line of code
int main()
{

    return 0;
}