// tc n*logn spc n gfg iterative
vector <int> bottomView(Node *root){
  vector<int> result;
  if(root==NULL) return result;
  queue<pair<Node*,int>> q;
  int hd=0;
  q.push({root,hd});
  map<int,int> mp;
  while(!q.empty()){
    Node* curr=q.front().first;
    hd=q.front().second;
    q.pop();
    mp[hd]=curr->data;
    if(curr->left) q.push({curr->left,hd-1});
    if(curr->right) q.push({curr->right,hd+1});
  }
  for(auto it: mp){
    result.push_back(it.second);
  }
  return result;
}

// tc n*logn spc n gfg recursive
void fillMap(Node* root,map<int,pair<int,int>>& mp,int hd,int height){
  if(root==NULL) return;
  if(mp.count(hd)==0) mp[hd]={root->data,height};
  else if(height>=mp[hd].second) mp[hd]={root->data,height};
  fillMap(root->left,mp,hd-1,height+1);
  fillMap(root->right,mp,hd+1,height+1);
}
vector <int> bottomView(Node *root){
  vector<int> answer;
  if(root==NULL) return answer;
  map<int,pair<int,int>> mp;
  int hd=0,height=0;
  fillMap(root,mp,hd,height);
  for(auto it1:mp){
    pair<int,int>p=it1.second;
    answer.push_back(p.first);
  }
  return answer;
}

// tc spc n gfg iterative
// I just replaced map with vector
void findMinMax(Node* root,int& min,int& max,int hd){
  if(root==NULL) return;
  if(min>hd){
    min=hd;
  }
  else if(max<hd){
    max=hd;
  }
  findMinMax(root->left,min,max,hd-1);
  findMinMax(root->right,min,max,hd+1);
}
vector <int> bottomView(Node *root){
  queue<pair<Node*,int>> q;
  int hd=0,min=0,max=0;
  q.push({root,hd});
  findMinMax(root,min,max,hd);
  vector<int> result(max-min+1);
  if(root==NULL) return result;
  while(!q.empty()){
    Node* curr=q.front().first;
    hd=q.front().second;
    q.pop();
    result[hd-min]=curr->data;
    if(curr->left)q.push({curr->left,hd-1});
    if(curr->right)q.push({curr->right,hd+1});
  }
  return result;
}
