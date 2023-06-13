class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0;
    int maxi = 0;
    int maxjump =0;
    for(int i=0 ; i<n && maxi<n-1 ; i++)
    {
        int curr= i+nums[i];
        maxjump = max(maxjump , curr);

        if(i==maxi && maxi<maxjump)
        {
            maxi = maxjump;
            jumps++;
        }
    }
    return jumps;
    }
};