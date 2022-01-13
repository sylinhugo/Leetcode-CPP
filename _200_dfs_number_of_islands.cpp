#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x)
            {
                ans += grid[y][x] - '0';
                dfs(grid, x, y, m, n);
            }
        return ans;
    }

private:
    void dfs(vector<vector<char>> &grid, int x, int y, int m, int n)
    {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0')
            return;
        grid[y][x] = '0';
        dfs(grid, x + 1, y, m, n);
        dfs(grid, x - 1, y, m, n);
        dfs(grid, x, y + 1, m, n);
        dfs(grid, x, y - 1, m, n);
    }
};

class Solution2
{
private:
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1')
            dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r + 1][c] == '1')
            dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1')
            dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c + 1] == '1')
            dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int nr = grid.size();
        if (!nr)
            return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r)
        {
            for (int c = 0; c < nc; ++c)
            {
                if (grid[r][c] == '1')
                {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};