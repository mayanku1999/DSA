// RECURSIVE
void postorderUtil(TreeNode* root){
  if(root==NULL) return;
  postorderUtil(root->left);
  postorderUtil(root->right);
  answer.push_back(root->val);
}

// ITERATIVE - APPROACH 1
// doing preorder (DRL) iteratively and then reversing the vector
stack<TreeNode*> s;
vector<int> answer;
TreeNode* curr=root;
while(!s.empty() or curr!=NULL){
  while(curr!=NULL){
    answer.push_back(curr->val);
    s.push(curr);
    curr=curr->right;
  }
  curr=s.top();
  s.pop();
  curr=curr->left;
}
reverse(answer.begin(),answer.end());
return answer;

// ITERATIVE - APPROACH
// we keep track of the previously printed node using 'last'
stack<TreeNode*> s;
TreeNode* last=NULL;
vector<int> answer;
while(!s.empty() or root!=NULL){
  if(root!=NULL){
    s.push(root);
    root=root->left;
  }else{
    TreeNode* curr=s.top();
    if(curr->right and last!=curr->right){
      root=curr->right;
    }else{
      answer.push_back(curr->val);
      s.pop();
      last=curr;
    }
  }
}
return answer;
