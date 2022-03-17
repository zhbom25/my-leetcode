//
// Created by zhaobo on 2022/3/7.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> vec(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 0) {
            vec[0][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0 && vec[i-1][0] == 1) {
                vec[i][0] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0 && vec[0][i-1] == 1) {
                vec[0][i] = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    vec[i][j] = vec[i][j-1] + vec[i-1][j];
                }
            }
        }
        return vec[m-1][n-1];
    }
};

int main(int argc, char** argv)
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution* solution = new Solution();
    int ret = solution->uniquePathsWithObstacles(obstacleGrid);
    cout << "ret : " << ret << endl;
    return 0;
}
