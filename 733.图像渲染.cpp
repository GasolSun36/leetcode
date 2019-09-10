/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        queue<pair<int, int>> Q;
        Q.push({sr, sc});
        int old = image[sr][sc]; //old为原来这个位置上面的颜色
        if (old == newColor)
        {
            return image; //如果old跟newColor一样，不需要修改直接返回（有一个测试点）
        }
        while (!Q.empty())
        {
            pair<int, int> temp = Q.front();
            Q.pop();                                                       //别忘删除
            image[temp.first][temp.second] = newColor;                     //更新颜色
            vector<pair<int, int>> V = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //设立四个方向的差值
            for (int i = 0; i < 4; i++)
            {
                int x = temp.first + V[i].first;
                int y = temp.second + V[i].second;
                if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == old)
                { //上述条件在题目中注意部分有
                    Q.push({x, y});
                }
            }
        }
        return image;
    }
};
