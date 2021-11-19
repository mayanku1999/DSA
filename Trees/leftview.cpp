// spc and tc n recursive gfg
void solve(Node* root,vector<int>& res,int& left,int level){
  if(root==NULL) return;
  if(left<level){
    left=level;
    res.push_back(root->data);
  }
  solve(root->left,res,left,level+1);
  solve(root->right,res,left,level+1);
}
vector<int> leftView(Node *root){
  vector<int> res;
  int left=-1,level=0;
  solve(root,res,left,level);
  return res;
}

// spc and tc n iterative gfg
vector<int> leftView(Node *root){
  vector<int> answer;
  if(root==NULL) return answer;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int k=q.size();
    for(int i=0;i<k;i+=1){
      Node* curr=q.front();
      q.pop();
      if(i==0) answer.push_back(curr->data);
      if(curr->left) q.push(curr->left);
      if(curr->right) q.push(curr->right);
    }
  }
  return answer;
}
