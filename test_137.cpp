#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & mask) != 0) {
                    cnt++;
                }
            }
            if (cnt % 3 != 0) {
                ret |= mask;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> vec = {1,1,2,2,0,0,2,1,0,3,4,4,5,4,5,5};
    Solution* solution = new Solution();
    int ret = solution->singleNumber(vec);
    cout << "ret : " << ret << endl;
    return 0;
}
