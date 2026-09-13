class Solution {
public:
    bool util(int i, int sum1, int total,
              vector<int>& nums, vector<vector<int>>& dp) {

        if (i == nums.size()) {
            return sum1 == total - sum1;
        }
        if (sum1 > total / 2)
    return false;

        if (dp[i][sum1] != -1)
            return dp[i][sum1];

        // Put nums[i] in subset2
        bool dontTake = util(i + 1, sum1, total, nums, dp);

        // Put nums[i] in subset1
        bool take = util(i + 1, sum1 + nums[i], total, nums, dp);

        return dp[i][sum1] = take || dontTake;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        if (total % 2 != 0)
            return false;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(total / 2 + 1, -1)
        );

        return util(0, 0, total, nums, dp);
    }
};