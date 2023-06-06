class Solution {
public:
    int change(int amount, vector<int>& coins) {
       int n = coins.size();
       vector<vector<int>> dp(n , vector<int>(amount+1, 0));

       for(int i=0 ; i<=amount ; i++)
       {
           dp[0][i] = (i%coins[0] == 0);
       } 

       for(int i=1 ; i<n ; i++)
       {
           for(int j=0 ; j<=amount ; j++)
           {
               int notpick = dp[i-1][j];
               int pick =0;
               if(j>=coins[i]) pick=dp[i][j-coins[i]];

               dp[i][j] = notpick+pick;
           }
       }
       return dp[n-1][amount];
    }
};