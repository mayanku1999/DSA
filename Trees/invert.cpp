// ITERATIVE STACK
if(root==NULL) return root;
stack<TreeNode*> s;
s.push(root);
while(!s.empty()){
  TreeNode* curr=s.top();
  s.pop();
  if(curr->left) s.push(curr->left);
  if(curr->right) s.push(curr->right);
  swap(curr->left,curr->right);
}
return root;

// ITERATIVE QUEUE
if(root==NULL) return root;
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
  TreeNode* curr=q.front();
  q.pop();
  if(curr->left) q.push(curr->left);
  if(curr->right) q.push(curr->right);
  swap(curr->left,curr->right);
}
return root;

// RECURSIVE
if(root==NULL) return root;
invertTree(root->left);
invertTree(root->right);
swap(root->right,root->left);
return root;
