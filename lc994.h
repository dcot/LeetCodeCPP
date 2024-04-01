//
// Created by clf on 2023/11/24.
//

#ifndef LEETCODECPP_LC994_H
#define LEETCODECPP_LC994_H
#include <bits/stdc++.h>
using namespace std;
class lc994 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 队列存坐标
        queue<pair<int,int>> queue;
        // 四个方向
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        // 已经访问的不在访问
        int visited[10][10] = {0};
        int minute = 0;
        //用腐败的橘子数量和橘子总数是否相等 来判断腐败不到橘子返回-1的情况
        int rottenCount = 0;
        int orangeCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rottenCount++;
                    orangeCount++;
                    queue.emplace(make_pair(i,j));
                }
                if (grid[i][j] == 1) {
                    orangeCount++;
                }
            }
        }

        if (rottenCount == orangeCount) return 0;
        //BFS 每一层的腐败橘子都生效后才开始计数
        int currentSize = queue.size();
        // 记录下一层的腐败橘子数量
        int nextSize = 0;
        while(!queue.empty()) {
            auto position = queue.front();
            queue.pop();
            currentSize--;
            int x = position.first;
            int y = position.second;
            if (!visited[x][y]) {
                visited[x][y] = 1;
                for (auto& dir : dirs) {
                    int x1 = x + dir[0];
                    int y1 = y + dir[1];
                    if (checkRange(x1,y1,rows,cols) && grid[x1][y1] == 1) {
                        grid[x1][y1] = 2;
                        rottenCount++;
                        queue.push(make_pair(x1,y1));
                        nextSize++;
                    }
                }
                if (nextSize!=0 && currentSize == 0) {
                    minute++;
                    currentSize = nextSize;
                    nextSize = 0;
                }
            }
        }

        return orangeCount == rottenCount ? minute : -1;
    }
    // 不能跑到grid外
    bool checkRange(int x, int y, int rows, int cols) {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            return true;
        } else {
            return false;
        }
    }
};
#endif //LEETCODECPP_LC994_H
