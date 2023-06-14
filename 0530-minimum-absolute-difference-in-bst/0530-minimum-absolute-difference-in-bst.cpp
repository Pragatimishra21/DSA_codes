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
    int getMinimumDifference(TreeNode* root) {
      stack<TreeNode*> st;
      int prev = INT_MAX;
      int mini = INT_MAX;
    TreeNode* curr = root;

    while(!st.empty() ||  curr!= NULL)
    {
        while(curr!= NULL)
        {
          st.push(curr);
          curr = curr->left;
        }

        curr = st.top();
        st.pop();

        if(prev != INT_MAX)
        {
            mini = min(mini , abs(curr->val - prev));
        }
        prev = curr->val;
        curr = curr->right;
    }
    return mini ;
    }
};