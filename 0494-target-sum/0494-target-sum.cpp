class Solution {
public:
    int solve(vector<int>& nums, int sum)
    {
       int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
           if(nums[0] == 0) dp[0][0] = 2;
           else dp[0][0] = 1;

           if(nums[0]!=0 && nums[0]<=sum)
           dp[0][nums[0]] = 1;

           for(int i=1 ; i<n ; i++)
           {
               for(int j=0 ; j<=sum ; j++)
               {
                   int notpick = dp[i-1][j];
                   int pick = 0;
                   if(nums[i]<=j) pick = dp[i-1][j-nums[i]];

                   dp[i][j] = notpick+pick;

               }
           }
           return dp[n-1][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
     int n=nums.size();
     int totsum = 0;
     for(int i=0 ; i<n ; i++)
     {
       totsum += nums[i];
     }
     if( totsum-target <0 || (totsum-target)%2 != 0) return 0;

    return solve(nums , (totsum-target)/2);
    }
};