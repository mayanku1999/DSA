// tc spc O(n sq) approach
//https://www.geeksforgeeks.org/print-binary-tree-vertical-order/

// RECURSIVE gfg (write preorder or postorder but not inorder)
//tc logn*logn*n spc n
map<int,map<int,vector<int>>> mp;
void solve(Node* root,int col,int row){
  if(root==NULL) return;
  mp[col][row].push_back(root->data);
  solve(root->left,col-1,row+1);
  solve(root->right,col+1,row+1);
}
vector<int> verticalOrder(Node *root){
  vector<int> answer;
  solve(root,0,0);
  for(auto it:mp){
    map<int,vector<int>> m=it.second;
    for(auto i:m){
      vector<int> a=i.second;
      for(int i=0;i<a.size();i+=1){
        answer.push_back(a[i]);
      }
    }
  }
  return answer;
}

// RECURSIVE (leetcode)
map<int,map<int,multiset<int>>> mp;
void solve(TreeNode* root, map<int,map<int,multiset<int>>>& mp, int col,int row){
  if(root==NULL) return;
  mp[col][row].insert(root->val);
  solve(root->left,mp,col-1,row+1);
  solve(root->right,mp,col+1,row+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
  solve(root,mp,0,0);
  vector<vector<int>> answer;
  // printing the answer
  for(auto it:mp){
    map<int,multiset<int>> values=it.second;
    vector<int> row;
    for(auto it2:values){
      multiset<int> multi_set=it2.second;
      for(auto it3:multi_set){
        row.push_back(it3);
      }
    }
    answer.push_back(row);
  }
  return answer;
}

// ITERATIVE gfg - level order traversal using queue
// tc o(n*log n) spc o(n)
// Use unordered_map to reduce tc to o(n)

vector<int> verticalOrder(Node *root){
  vector<int> answer;
  int hd=0;
  map<int,vector<int>> mp;
  if(root==NULL) return answer;
  queue<pair<Node*,int>> q;
  q.push(make_pair(root,hd));
  while(!q.empty()){
    int k=q.size();
    for(int i=0;i<k;i+=1){
      pair<Node*,int> pair=q.front();
      q.pop();
      Node* node=pair.first;
      hd=pair.second;
      mp[hd].push_back(node->data);
      if(node->left) q.push(make_pair(node->left,hd-1));
      if(node->right) q.push(make_pair(node->right,hd+1));
    }
  }
  for(auto it: mp){
    for(int i=0;i<it.second.size();i+=1){
      answer.push_back(it.second[i]);
    }
  }
  return answer;
}

// ITERATIVE leetcode

vector<vector<int>> verticalTraversal(TreeNode* root) {
  map<int,map<int,multiset<int>>> mp;
  queue<pair<TreeNode*,pair<int,int>>> q;
  q.push({root,{0,0}});
  while(!q.empty()){
    pair<TreeNode*,pair<int,int>> p=q.front();
    q.pop();
    mp[p.second.first][p.second.second].insert(p.first->val);
    if(p.first->left) q.push({p.first->left,{p.second.first-1,p.second.second+1}});
    if(p.first->right) q.push({p.first->right,{p.second.first+1,p.second.second+1}});
  }
  vector<vector<int>> answer;
  for(auto it1:mp){
    map<int,multiset<int>> val=it1.second;
    vector<int> rows;
    for(auto it2:val){
      multiset<int> m=it2.second;
      for(auto it3:m)  rows.push_back(it3);
    }
    answer.push_back(rows);
  }
  return answer;
}










class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};