//gfg bfs tc o(v+e) sp o(v) (adj was given so v is space for queue and visited)
bool findCycleBFS(int start, vector<int> adj[],vector<bool>& visited){
  queue<pair<int,int>> q;
  q.push({start,-1});
  visited[start]=true;
  while(!q.empty()){
    int node=q.front().first;
    int parent=q.front().second;
    q.pop();
    for(auto it:adj[node]){
      if(!visited[it]){
        q.push({it,node});
        visited[it]=true;
      }else{
        if(parent!=it) return true;
      }
    }
  }
  return false;
}
bool isCycle(int v, vector<int>adj[]){
  int i;
  vector<bool> visited(v,0);
  for(i=0;i<v;i+=1){
    if(!visited[i] and findCycleBFS(i,adj,visited)) return true;
  }
  return false;
}

// gfg dfs tc v+e sp v
bool findCycleDFS(int start, int parent, vector<int> adj[],vector<bool>& visited){
  visited[start]=true;
  for(auto it: adj[start]){
    if(!visited[it]){
      if(findCycleDFS(it,start,adj,visited)) return true;
    }else{
      if(it!=parent) return true;
    }
  }
  return false;
}
bool isCycle(int v, vector<int>adj[]){
  int i;
  vector<bool> visited(v,0);
  for(i=0;i<v;i+=1){
    if(!visited[i] and findCycleDFS(i,-1,adj,visited)) return true;
  }
  return false;
}
