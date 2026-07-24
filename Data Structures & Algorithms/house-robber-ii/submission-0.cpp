
#include <cstring>

class Solution {
public:
    int t[201][201];

    int solve(vector<int>& nums, int i, int j) {
        if (i > j) {
            return 0;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        int robCurrent = nums[i] + solve(nums, i + 2, j);
        int skipCurrent = solve(nums, i + 1, j);

        return t[i][j] = max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return nums[0];
        }

        memset(t, -1, sizeof(t));
        int case1 = solve(nums, 0, n - 2);

        memset(t, -1, sizeof(t));
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};