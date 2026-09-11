class Solution {
public:
int util(int i, int amount, vector<int>& coins, vector<vector<int>>&dp){
    if(i>=coins.size()) return 0;
    if(amount==0) return 1;
    if(dp[i][amount] != -1) return dp[i][amount];
    int take=0, notTake=0;
    if(coins[i] <= amount) take=util(i, amount-coins[i], coins, dp);
    notTake=util(i+1, amount, coins, dp);

    return dp[i][amount]=take+notTake;
}
    int change(int amount, vector<int>& coins) {
    vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
    return util(0, amount, coins, dp);    
    }
};
