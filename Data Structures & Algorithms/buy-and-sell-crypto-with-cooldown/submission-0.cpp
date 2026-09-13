class Solution {
public:

    int util(int i, int soldYest, vector<int>& prices,
             vector<vector<int>>& dp) {
                if(i>=prices.size()) return 0;
        if(dp[i][soldYest] != -1) return dp[i][soldYest];
        

        if(soldYest){
            int buyToday= -prices[i] + util(i+1, 0, prices, dp);
            int notDo=util(i+1, 1,prices,  dp);
            return dp[i][soldYest]=max(buyToday, notDo);
        }
        else{
            int hold=util(i+1, 0, prices, dp);
            int sellToday=prices[i]+util(i+2, 1,prices,  dp);
            return dp[i][soldYest]=max(hold, sellToday);
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(
            n, vector<int>(2, -1)
        );

        return util(0, 1, prices, dp);
    }
};
