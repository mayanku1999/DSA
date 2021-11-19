int diameter(TreeNode* root, int& answer){
  if(root==NULL) return -1;
  int l=diameter(root->left,answer);
  int r=diameter(root->right,answer);
  answer=max(answer,l+r+2);
  return max(l,r)+1;
}
int diameterOfBinaryTree(TreeNode* root) {
  int answer=INT_MIN;
  diameter(root,answer);
  return answer;
}




// mySol
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
    int solve(TreeNode*root,int &ans){
         if(root==NULL)return 0;
        int l = solve(root->left,ans);
        int r= solve(root->right,ans);
        int h=max(l,r)+1;
        ans=max(ans,l+r);
        return h;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int ans=-1;
        solve(root,ans);
        return ans;
    }
};