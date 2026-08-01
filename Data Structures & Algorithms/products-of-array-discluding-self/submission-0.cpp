class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int zeroCount = 0;

        for (int x : nums) {
            if (x == 0)
                zeroCount++;
            else
                product *= x;
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (zeroCount > 1) {
                ans[i] = 0;
            }
            else if (zeroCount == 1) {
                if (nums[i] == 0)
                    ans[i] = product;
                else
                    ans[i] = 0;
            }
            else {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};