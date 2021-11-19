// APPROACH-1 queue based APPROACH
if(root==NULL){
  return;
}
queue<struct bstNode*> q;
q.push(root);
while(!q.empty()){
  struct bstNode* curr=q.front();
  printf("%d ",curr->data);
  if(curr->left!=NULL) q.push(curr->left);
  if(curr->right!=NULL) q.push(curr->right);
  q.pop();
}

// APPROACH-2 (from leetcode)
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
vector<vector<int>> answer;
if(root==NULL) return answer;
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
  int k=q.size();
  vector<int> rows;
  for(int i=0;i<k;i+=1){
    TreeNode* curr=q.front();
    q.pop();
    rows.push_back(curr->val);
    if(curr->left) q.push(curr->left);
    if(curr->right) q.push(curr->right);
  }
  answer.push_back(rows);
}
return answer;

// APPROACH-3
vector<vector<int>> answer;
void levelOrderUtil(TreeNode* root,int level){
  if(root==NULL) return;
  if(level==answer.size()) answer.push_back(vector<int>());
  answer[level].push_back(root->val);
  levelOrderUtil(root->left,level+1);
  levelOrderUtil(root->right,level+1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
  levelOrderUtil(root,0);
  return answer;
}
