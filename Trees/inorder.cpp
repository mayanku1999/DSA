// RECURSIVE
void inorderUtil(TreeNode* root){
  if(root==NULL) return;
  inorderUtil(root->left);
  answer.push_back(root->val);
  inorderUtil(root->right);
}

// ITERATIVE
stack<TreeNode*> s;
TreeNode* curr=root;
vector<int> answer;
while(!s.empty() or curr!=NULL){
  while(curr!=NULL){
    s.push(curr);
    curr=curr->left;
  }
  curr=s.top();
  s.pop();
  answer.push_back(curr->val);
  curr=curr->right;
}
return answer;
