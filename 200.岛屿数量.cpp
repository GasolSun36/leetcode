/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int sr, int sc)
    {
        int nr = grid.size();    //row即行数
        int nc = grid[0].size(); //colomn即列数
        grid[sr][sc] = '0';      //遍历后置为0
        //如果该位置的上下左右不超过边界并且等于1的话，继续对他们进行dfs
        if (sr - 1 >= 0)
        {
            if (grid[sr - 1][sc] == '1')
            {
                dfs(grid, sr - 1, sc);
            }
        }
        if (sr + 1 < nr)
        {
            if (grid[sr + 1][sc] == '1')
            {
                dfs(grid, sr + 1, sc);
            }
        }
        if (sc - 1 >= 0)
        {
            if (grid[sr][sc - 1] == '1')
            {
                dfs(grid, sr, sc - 1);
            }
        }
        if (sc + 1 < nc)
        {
            if (grid[sr][sc + 1] == '1')
            {
                dfs(grid, sr, sc + 1);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int nr = grid.size();
        if (!nr) //一定要在nc之前，如果nr为0，那么根本就没有grid[0]
        {
            return 0;
        }
        int nc = grid[0].size();
        int count = 0;
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++; //图的一个连通分量只进行一次dfs，所以由次数看连通分量（即岛的数量）
                }
            }
        }
        return count;
    }
};
