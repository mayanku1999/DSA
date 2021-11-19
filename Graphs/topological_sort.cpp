// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that
// for every directed edge u v, vertex u comes before v in the ordering.
// Topological Sorting for a graph is not possible if the graph is not a DAG.

// gfg dfs tc v+e sp n+n+n(res+stack+visited) asp n(recursion)
stack<int> s;
void findTopoSort(vector<bool>& visited, vector<int> adj[],int start){
  visited[start]=true;
  for(auto it:adj[start]){
    if(!visited[it]){
      findTopoSort(visited,adj,it);
    }
  }
  s.push(start);
}
vector<int> topoSort(int v, vector<int> adj[]){
  vector<bool> visited(v,false);
  for(int i=0;i<v;i+=1){
    if(!visited[i]) findTopoSort(visited,adj,i);
  }
  vector<int> res;
  while(!s.empty()){
    res.push_back(s.top());
    s.pop();
  }
  return res;
}

// kahn's algorithm - topoSort using bfs
// tc v+e sp v+v+v(result,queue,indegree)
vector<int> topoSort(int v, vector<int> adj[]) {
  vector<int> indegree(v,0);
  vector<int> result;
  for(int i=0;i<v;i+=1){
    for(auto it: adj[i]){
      indegree[it]+=1;
    }
  }
  queue<int> q;
  for(int i=0;i<v;i+=1){
    if(indegree[i]==0) q.push(i);
  }
  while(!q.empty()){
    int node=q.front();
    q.pop();
    result.push_back(node);
    for(auto it:adj[node]){
      indegree[it]-=1;
      if(indegree[it]==0) q.push(it);
    }
  }
  return result;
}
