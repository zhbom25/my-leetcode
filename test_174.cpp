//
// Created by zhaobo on 2022/3/7.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 0;
        int row = dungeon.size();
        int low = dungeon[0].size();
        vector<vector<vector<int>>> vec(row, vector<vector<int>>(low, vector<int>(2, 0)));
        vec[0][0][0] = dungeon[0][0];
        if (dungeon[0][0] >= 0) {
            vec[0][0][1] = 0;
        } else {
            vec[0][0][1] = -1 * dungeon[0][0];
        }
        for (int i = 1; i < row; i++) {
            vec[i][0][0] = vec[i-1][0][0] + dungeon[i][0];
            if (dungeon[i][0] >= 0) {
                vec[i][0][1] = vec[i-1][0][1];
            } else {
                vec[i][0][1] = vec[i-1][0][1] - dungeon[i][0];
            }
        }
        for (int j = 1; j < low; j++) {
            vec[0][j][0] = vec[0][j-1][0] + dungeon[0][j];
            if (dungeon[0][j] >= 0) {
                vec[0][j][1] = vec[0][j-1][1];
            } else {
                vec[0][j][1] = vec[0][j-1][1] - dungeon[0][j];
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < low; j++) {
                if (dungeon[i][j] >= 0) {
                    if (vec[i-1][j][1] >= vec[i][j-1][1]) {
                        vec[i][j][0] = vec[i][j-1][0] + dungeon[i][j];
                        vec[i][j][1] = vec[i][j-1][1];
                    } else {
                        vec[i][j][0] = vec[i-1][j][0] + dungeon[i][j];
                        vec[i][j][1] = vec[i-1][j][1];
                    }
                } else {
                    if (vec[i-1][j][1] >= vec[i][j-1][1]) {
                        vec[i][j][0] = vec[i][j-1][0] + dungeon[i][j];
                    } else {
                        vec[i][j][0] = vec[i-1][j][0] + dungeon[i][j];
                    }
                    if (vec[i][j][0] < 0) {
                        vec[i][j][1] = max(-1*vec[i][j][0], vec[i][j][1]);
                    }
                }
                if (vec[i][j][0] < 0 && vec[i][j][1] + vec[i][j][0] < 0) {
                    vec[i][j][1] = -1 * vec[i][j][0];
                }
                cout << "i : " << i << endl;
                cout << "j : " << j << endl;
                cout << "i_j_0 : " << vec[i][j][0] << endl;
                cout << "i_j_1 : " << vec[i][j][1] << endl;
            }
        }
        return vec[row-1][low-1][1]+1;
    }
};

int main(int argc, char** argv)
{
    vector<vector<int>> vec = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution* solution = new Solution();
    int ret = solution->calculateMinimumHP(vec);
    cout << "ret : " << ret << endl;
    return 0;
}
