/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push (root);
        int ans = -1;
         int level = 0;
        int maxi = INT_MIN;
        while(!q.empty())
        {
         level++;
         int sum = 0;
         int size = q.size();
         for(int i=0 ; i<size ; i++)
         {
         TreeNode* node = q.front();
         q.pop();
         sum += node->val ;

         if(node->left) q.push(node->left);
         if(node->right) q.push(node->right);
         }
         if(sum > maxi)
         {
             maxi = sum ;
             ans = level;
         }
        }
       return ans; 
    }
};