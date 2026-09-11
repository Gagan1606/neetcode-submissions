class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int imax=text1.size(), jmax=text2.size();
        vector<vector<int>>dp(imax+1, vector<int>(jmax+1));
        
        for(int i=0; i<imax; i++){
            dp[i][0]=0;
        }
                for(int j=0; j<jmax; j++){
            dp[0][j]=0;
        }

        for(int i=1; i<=imax; i++){
            for(int j=1; j<=jmax; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;}
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[imax][jmax];
    }
};
