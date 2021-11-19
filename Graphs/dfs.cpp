// tc: o(v+e)
// sp: o(v)+o(v)+o(v+e) // visited, queue and adj list
//
// nodes are from 1 to v

void dfs(vector<int> adj_list[],int i,vector<bool> visited){
  stack<int> s;
  s.push(i);
  visited[i]=true;
  while(!s.empty()){
    int p=s.top();
    s.pop();
    cout<<p<<" ";
    for(auto it:adj_list[p]){
      if(!visited[it]){
        s.push(it);
        visited[it]=true;
      }
    }
  }
}
vector<bool> visited(v+1,false);
// disconnected components will be taken care of
for(i=1;i<=v;i+=1){
  if(!visited[i]){
    dfs(adj_list,i,visited);
  }
}

// dfs recursive
void dfs(vector<int> adj_list[],int i,vector<bool>& visited){
  cout<<i<<" ";
  visited[i]=true;
  for(auto it: adj_list[p]){
    if(!visited[it]){
      dfs(adj_list,it,visited);
    }
  }
}
for(i=1;i<=v;i+=1){
  if(!visited[i]){
    dfs(adj_list,i,visited);
  }
}
