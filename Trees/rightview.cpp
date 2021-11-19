// tc n sp n ITERATIVE
vector<int> answer;
if(root==NULL) return answer;
int d,right=-1;
queue<pair<TreeNode*,int>> q;
q.push({root,0});
while(!q.empty()){
  TreeNode* curr=q.front().first;
  d=q.front().second;
  q.pop();
  if(d>right){
    right=d;
    answer.push_back(curr->val);
  }
  if(curr->right) q.push({curr->right,d+1});
  if(curr->left) q.push({curr->left,d+1});
}
return answer;

// tc n spc n recursive
void solve(TreeNode* root,vector<int> &answer,int level,int &right){
  if(root==NULL) return;
  if(right<level){
    right=level;
    answer.push_back(root->val);
  }
  solve(root->right,answer,level+1,right);
  solve(root->left,answer,level+1,right);
}
vector<int> rightSideView(TreeNode* root) {
  vector<int> answer;
  int right=-1;
  solve(root,answer,0,right);
  return answer;
}
