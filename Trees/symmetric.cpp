// RECURSIVE
bool check(TreeNode* root1,TreeNode* root2){
  if(root1==NULL and root2==NULL) return true;
  else if(root1==NULL||root2==NULL) return false;
  else if(root1->val!=root2->val) return false;
  return check(root1->left,root2->right) and check(root1->right,root2->left);
}
bool isSymmetric(TreeNode* root) {
  return check(root->left,root->right);
}

// ITERATIVE
queue<TreeNode*> q;
q.push(root->left);
q.push(root->right);
while(!q.empty()){
  TreeNode* left=q.front();
  q.pop();
  TreeNode* right=q.front();
  q.pop();
  if(left==NULL and right==NULL) continue;
  if(left==NULL||right==NULL) return false;
  if(left->val!=right->val) return false;
  q.push(left->left);
  q.push(right->right);
  q.push(left->right);
  q.push(right->left);
}
return true;
