#include <bits/stdc++.h>
using namespace std;
//********** optimal approach (tech aroda by Navidita youtube)
class Solution
{
public:
    bool solve(int index, int i, int j, int &m, int &n, string &word, vector<vector<char>> &board)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index])
        {
            return false;
        }
        bool ans = false;
        if (word[index] == board[i][j])
        {
            board[i][j] = '*';
            ans = solve(index + 1, i + 1, j, m, n, word, board) ||
                  solve(index + 1, i, j + 1, m, n, word, board) ||
                  solve(index + 1, i - 1, j, m, n, word, board) ||
                  solve(index + 1, i, j - 1, m, n, word, board);
            board[i][j] = word[index];
        }
        return ans;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int index = 0;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[index])
                {
                    if (solve(index, i, j, m, n, word, board))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
//******* vissited matrix appraoch
class Solution
{
public:
    bool solve(int index, int i, int j, int &m, int &n, string &word, vector<vector<char>> &board, vector<vector<bool>> &visited)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] == true || board[i][j] != word[index])
        {
            return false;
        }
        bool ans = false;
        if (word[index] == board[i][j])
        {
            visited[i][j] = true;
            ans = solve(index + 1, i + 1, j, m, n, word, board, visited) ||
                  solve(index + 1, i, j + 1, m, n, word, board, visited) ||
                  solve(index + 1, i - 1, j, m, n, word, board, visited) ||
                  solve(index + 1, i, j - 1, m, n, word, board, visited);
            visited[i][j] = false;
        }
        return ans;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int index = 0;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[index])
                {
                    if (solve(index, i, j, m, n, word, board, visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}