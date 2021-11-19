// APPROACH 1
// Simply find the level order and reverse the answer
vector<vector<int>> answer;
void levelOrderUtil(TreeNode* root,int level){
  if(root==NULL) return;
  if(level==answer.size()) answer.push_back(vector<int>());
  answer[level].push_back(root->val);
  levelOrderUtil(root->left,level+1);
  levelOrderUtil(root->right,level+1);
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
  levelOrderUtil(root,0);
  reverse(answer.begin(),answer.end());
  return answer;
}

// APPROACH 2
void levelOrderUtil(TreeNode* root,int level,vector<vector<int>>& answer){
  if(root==NULL) return;
  answer[level].push_back(root->val);
  levelOrderUtil(root->left,level-1,answer);
  levelOrderUtil(root->right,level-1,answer);
}
int calcHeight(TreeNode* root){
  if(root==NULL) return -1;
  return 1+max(calcHeight(root->left),calcHeight(root->right));
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
  int height=calcHeight(root);
  vector<vector<int>> answer(height+1);
  levelOrderUtil(root,height,answer);
  return answer;
}

// APPROACH 3 https://www.geeksforgeeks.org/reverse-level-order-traversal/
// using queue and stack. We push the right child first in the queue and then the left child

// APPROACH 4
vector<vector<int>> res;
if(root==NULL) return res;
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
  int k=q.size();
  vector<int> rows;
  for(int i=0;i<k;i+=1){
    TreeNode* curr=q.front();
    rows.push_back(curr->val);
    q.pop();
    if(curr->left) q.push(curr->left);
    if(curr->right) q.push(curr->right);
  }
  res.push_back(rows);
}
reverse(res.begin(),res.end());
return res;









// my submitted code
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
    int heightOfTree(TreeNode*root){
        if(root==NULL)return 0;
        return max(heightOfTree(root->left),heightOfTree(root->right)) + 1;
        
    }
    void find(TreeNode*root,vector<vector<int>>&ans,int h){
        if(!root)return ;
        ans[h].push_back(root->val);
        find(root->left,ans,h-1);
        find(root->right,ans,h-1);
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int height = heightOfTree(root);
        vector<vector<int>> ans(height);
        find(root,ans,height-1);
        return ans;
    }
};