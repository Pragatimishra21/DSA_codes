class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       int n = grid.size();
       int ans = 0;
       map <vector<int> , int> mpp;
       for(vector<int> row : grid)
       {
           mpp[row]++;
       } 

       for(int i=0 ; i<n ; i++)
       {
           vector<int> list={};
           for(int j=0 ; j<n ; j++)
           {
               list.push_back(grid[j][i]);
           }
           ans += mpp[list];
       }
       return ans;
    }
};