class Solution {
   public:
    int util(int i, vector<int>& coins, int amount, vector<vector<int>> &dp) {
        if (amount == 0) return 0;
        if (i >= coins.size()) {
           return INT_MAX;
        }
        // if (coins[i] > amount && amount != 0) return INT_MAX;
        if(dp[i][amount] != -2) return dp[i][amount];
        int takeGoNext = INT_MAX;
        int dontTake = util(i + 1, coins, amount, dp);
        if (coins[i] <= amount) {
            int x = util(i, coins, amount - coins[i], dp);
            if(x != INT_MAX) takeGoNext = 1 + x;
            // takeStay = 1 + util(i, coins, amount - coins[i], dp);
        }
        // if(takeGoNext == -1 || dontTake== -1 || takeStay== -1) return dp[i][amount]=-1;
        // vector<int> temp={takeGoNext, dontTake, takeStay};
        // for(auto &x: temp) if(x==0) x=INT_MAX;
        // if(takeGoNext == INT_MAX && dontTake == INT_MAX) return dp[i][amount]=-1;
        return dp[i][amount] = min({takeGoNext, dontTake});
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -2));
        int x = util(0, coins, amount, dp);
        return x==INT_MAX? -1:x;
    }
};
