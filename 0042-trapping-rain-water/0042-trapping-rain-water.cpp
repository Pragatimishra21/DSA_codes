class Solution {
public:
    int trap(vector<int>& height) {
     int l = 0 ;
     int r= height.size()-1;
     int leftmax = 0;
     int rmax = 0;
     int ans = 0;
     while(l<=r)
     {
         if(height[l]<=height[r])
         {
             if(height[l]>=leftmax)
             leftmax = height[l];
             else
             ans += leftmax-height[l];
             l++;
         }
         else
         {
             if(height[r]>=rmax)
             rmax = height[r];
             else
             ans += rmax-height[r];

             r--;
         }
     }
     return ans;
    }
};