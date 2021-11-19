// algorithm for detecting cycle in an undirected graph wont work here
// consider this digraph with edges (1,2) (2,3) (1,4) (4,3)

// gfg dfs tc v+e sp v
bool checkCycle(int start, vector<int> adj[],vector<bool>& visited,vector<bool>& dfs_visited){
  visited[start]=true;
  dfs_visited[start]=true;
  for(auto it: adj[start]){
    if(!visited[it]){
      if(checkCycle(it,adj,visited,dfs_visited)) return true;
    }else{
      if(dfs_visited[it]) return true;
    }
  }
  dfs_visited[start]=false;
  return false;
}
bool isCyclic(int v, vector<int> adj[]) {
  vector<bool> visited(v,0);
  vector<bool> dfs_visited(v,0);
  for(int i=0;i<v;i+=1){
    if(!visited[i] and checkCycle(i,adj,visited,dfs_visited)) return true;
  }
  return false;
}

// gfg bfs kahn's algo
// tc v+e sp v+v(queue,indegree)
bool isCyclic(int v, vector<int> adj[]){
  vector<int> indegree(v,0);
  int i,count=0;
  for(i=0;i<v;i+=1){
    for(auto it: adj[i]) indegree[it]+=1;
  }
  queue<int> q;
  for(i=0;i<v;i+=1){
    if(indegree[i]==0) q.push(i);
  }
  while(!q.empty()){
    int node=q.front();
    q.pop();
    count+=1;
    for(auto it:adj[node]){
      indegree[it]-=1;
      if(indegree[it]==0) q.push(it);
    }
  }
  // we generated a valid topo sort
  if(count==v) return false;
  return true;
}
