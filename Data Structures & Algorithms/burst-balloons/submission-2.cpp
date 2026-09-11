class Solution {
public:
int util(int l, int r, vector<int>& a,
             vector<vector<int>>& dp) {
                 if (dp[l][r] != -1)
            return dp[l][r];
            if (l > r) return 0;
            int maxi=0;
        //dp[i][]=
        for(int k = l; k <= r; k++){
            int coinsForThis=a[l - 1] * a[k] * a[r + 1];
            int left = util(l, k-1, a, dp);
            int right = util(k+1, r, a, dp);

            maxi=max(maxi, left+right+coinsForThis);
        }
        return dp[l][r] = maxi;

    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++)
            a[i + 1] = nums[i];

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return util(1, n, a, dp);
    }
};
