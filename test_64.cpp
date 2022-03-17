//
// Created by zhaobo on 2022/3/6.
//
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        return _minPathSum(grid, 0, 0);
    }

    int _minPathSum(vector<vector<int>>& grid, int row, int col)
    {
        int _row = grid.size()-1;
        int _col = grid[0].size()-1;
        if (row >= _row && col >= _col) {
            return grid[_row][_col];
        }
        int cur = grid[row][col];
        if (row < _row && col < _col) {
            int sum_r = _minPathSum(grid, row, col+1);
            int sum_d = _minPathSum(grid, row+1, col);
            return min(sum_r+cur, sum_d+cur);
        }
        if (row < _row) {
            return cur + _minPathSum(grid, row+1, col);
        }
        if (col < _col) {
            return cur + _minPathSum(grid, row, col+1);
        }
        return 0;
    }
    int minPathSum2(vector<vector<int>>& grid)
    {
        int row = grid.size() - 1;         // 行
        int col = grid[0].size() - 1;      // 列
        if (row < 0 || col < 0) return 0;
        for (int i = 1; i <= row; i++) {
            grid[i][0] += grid[i-1][0];
        }
        for (int i = 1; i <= col; i++) {
            grid[0][i] += grid[0][i-1];
        }
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[row][col];
    }
};

int main(int argc, char** argv)
{
    vector<vector<int>> vec = {{5,0,1,1,2,1,0,1,3,6,3,0,7,3,3,3,1},
                               {1,4,1,8,5,5,5,6,8,7,0,4,3,9,9,6,0},
                               {2,8,3,3,1,6,1,4,9,0,9,2,3,3,3,8,4},
                               {3,5,1,9,3,0,8,3,4,3,4,6,9,6,8,9,9},
                               {3,0,7,4,6,6,4,6,8,8,9,3,8,3,9,3,4},
                               {8,8,6,8,3,3,1,7,9,3,3,9,2,4,3,5,1},
                               {7,1,0,4,7,8,4,6,4,2,1,3,7,8,3,5,4},
                               {3,0,9,6,7,8,9,2,0,4,6,3,9,7,2,0,7},
                               {8,0,8,2,6,4,4,0,9,3,8,4,0,4,7,0,4},
                               {3,7,4,5,9,4,9,7,9,8,7,4,0,4,2,0,4},
                               {5,9,0,1,9,1,5,9,5,5,3,4,6,9,8,5,6},
                               {5,7,2,4,4,4,2,1,8,4,8,0,5,4,7,4,7},
                               {9,5,8,6,4,4,3,9,8,1,1,8,7,7,3,6,9},
                               {7,2,3,1,6,3,6,6,6,3,2,3,9,9,4,4,8}};
    Solution* solution = new Solution();
    time_t myt1 = time(NULL);
    int ret = solution->minPathSum(vec);
    time_t myt2 = time(NULL);
    cout << "time1 used : " << myt2 - myt1 << endl;
    cout << "value1 : " << ret << endl;
    time_t myt3 = time(NULL);
    int ret2 = solution->minPathSum2(vec);
    time_t myt4 = time(NULL);
    cout << "time2 used : " << myt4 - myt3 << endl;
    cout << "value2 : " << ret2 << endl;
    return 0;
}
