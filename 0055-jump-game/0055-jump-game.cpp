class Solution {
public:
    bool canJump(vector<int>& nums) {
   int maxreach =0;
   for(int i=0 ; i<nums.size() ; i++)
   {
       if(i+nums[i] > maxreach) maxreach = i+nums[i];

       if(maxreach == nums.size()-1) return true;

       if(i>=maxreach) return false;
   }
   return true;
    }
};