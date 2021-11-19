// tc o(n) sp o(n)
// https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
vector<int> topView(Node *root){
  int left=0,right=0;
  queue<pair<Node*,int>> q;
  int hd=0;
  q.push({root,hd});
  stack<int> s;
  vector<int> v;
  while(!q.empty()){
    Node* curr=q.front().first;
    hd=q.front().second;
    q.pop();
    if(left>hd){
      left=hd;
      s.push(curr->data);
    }
    else if(right<hd){
      right=hd;
      v.push_back(curr->data);
    }
    if(curr->left) q.push({curr->left,hd-1});
    if(curr->right) q.push({curr->right,hd+1});
  }
  vector<int> answer;
  while(!s.empty()){
    answer.push_back(s.top());
    s.pop();
  }
  answer.push_back(root->data);
  for(int i:v) answer.push_back(i);
  return answer;
}

// Topview gfg ITERATIVE
// sp o(n) tc o(n*logn)
vector<int> topView(Node *root){
  map<int,int> mp;
  int hd=0;
  queue<pair<Node*,int>> q;
  q.push({root,hd});
  while(!q.empty()){
    pair<Node*,int> p=q.front();
    q.pop();
    Node *curr=p.first;
    hd=p.second;
    if(mp.find(hd)==mp.end()){
      mp[hd]=(curr->data);
    }
    if(curr->left) q.push({curr->left,hd-1});
    if(curr->right) q.push({curr->right,hd+1});
  }
  vector<int> answer;
  for(auto it:mp){
    answer.push_back(it.second);
  }
  return answer;
}

// Topview recursive gfg
// sp o(n) tc o(n*logn)
void fillMap(Node* root,map<int,pair<int,int>> &mp,int hd,int d){
  if(root==NULL) return;
  if(mp.count(hd)==0) mp[hd]={root->data,d};
  else if(d<mp[hd].second) mp[hd]={root->data,d};
  fillMap(root->left,mp,hd-1,d+1);
  fillMap(root->right,mp,hd+1,d+1);
}
vector<int> topView(Node *root){
  map<int,pair<int,int>> mp;
  fillMap(root,mp,0,0);
  vector<int> answer;
  for(auto it:mp){
    answer.push_back(it.second.first);
  }
  return answer;
}






















class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};