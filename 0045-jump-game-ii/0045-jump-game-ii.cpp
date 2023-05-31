class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
       int jumps = 0;
       int max_reach = 0;
       int max_jumps = 0;
       int curr = 0;
       for(int i=0 ; i<n && max_reach<n-1 ; i++)
       {
         curr = i+nums[i];
         max_jumps = max(max_jumps , curr);

         if(i==max_reach && max_reach<max_jumps)
         {
             jumps++;
             max_reach = max_jumps;
         }
       }
       if(max_reach < n-1)
         return -1;

       return jumps;  
    }
};