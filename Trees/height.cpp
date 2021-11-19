//RECURSIVE-DFS
int height(node *root){
  if(root==NULL) return 0;
  return max(height(root->left),height(root->right))+1;
}

//ITERATIVE-BFS
int height(TreeNode* root){
  if(root==NULL) return 0;
  queue<TreeNode*> q;
  q.push(root);
  int res=0;
  while(!q.empty()){
    res+=1;
    int k=q.size();
    for(int i=0;i<k;i+=1){
        TreeNode* p=q.front();
        q.pop();
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
  }
  return res;
}
