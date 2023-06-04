class Solution {
public:
   bool solve(vector<int>& nums , int n , int k)
   {
       vector<vector<bool>>dp(n , vector<bool>(k+1 , false));
       for(int i=0 ; i<n ; i++) dp[i][0] = true;

       if(nums[0]<=k) dp[0][nums[0]] = true;
  
    for(int i=1 ; i<n ; i++)
    {
        for(int j=1 ; j<k+1 ; j++)
        {
          bool notake = dp[i-1][j];
          bool take = false;
          if(j>=nums[i]) take = dp[i-1][j-nums[i]];

          dp[i][j] = notake || take;
        }
    }     
    return dp[n-1][k];
   }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for(int i=0 ; i<n ; i++) totsum += nums[i];
        if(totsum%2 != 0) return false;
        else
        return solve(nums , n , totsum/2);
    }
};