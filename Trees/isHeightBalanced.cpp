Refer Notebook, for pair<height, isBalanced> approach
tc O(N)
sc O(N)


second approach 
tc O(N)
sc O(1)


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
    bool ans=true;
    int height(TreeNode*root){
        if(!root)return 0; 
        int l=height(root->left);
        int r=height (root->right);
        if(abs(l-r)>1)ans=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};