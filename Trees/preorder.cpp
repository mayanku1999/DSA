// RECURSIVE
void preorderUtil(TreeNode* root){
  if(root==NULL) return;
  answer.push_back(root->val);
  preorderUtil(root->left);
  preorderUtil(root->right);
}

// ITERATIVE
stack<TreeNode*> s;
vector<int> answer;
TreeNode* curr=root;
while(curr!=NULL or !s.empty()){
  while(curr!=NULL){
    s.push(curr);
    answer.push_back(curr->val);
    curr=curr->left;
  }
  curr=s.top();
  s.pop();
  curr=curr->right;
}
return answer;
