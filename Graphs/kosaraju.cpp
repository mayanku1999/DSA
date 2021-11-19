// scc (strongly connected component) is a component where if you start
// from any node, you can reach every other node in that component

// step 1) sort all nodes in order of finishing time(use topo sort)
// step 2) tranpose the graph
// step 3) do the dfs acc to the finishing time

// gfg tested tc v+e sp v+e
void topoSort(int start,vector<int> adj[],stack<int>& s,vector<bool>& visited){
  visited[start]=true;
  for(auto it:adj[start]){
    if(!visited[it]) topoSort(it,adj,s,visited);
  }
  s.push(start);
}
void transpose(vector<int> adj[],int v,vector<int> new_adj[]){
  for(int i=0;i<v;i+=1){
    for(auto it: adj[i]){
      new_adj[it].push_back(i);
    }
  }
}
void dfsRev(vector<bool>& visited,int start,vector<int> new_adj[]){
  // you can also print scc by cout<<start<<" ";
  visited[start]=true;
  for(auto it:new_adj[start]){
    if(!visited[it]) dfsRev(visited,it,new_adj);
  }
}
int kosaraju(int v, vector<int> adj[]){
  stack<int> s;
  vector<bool> visited(v,false);
  // step1 do topological sorting
  for(int i=0;i<v;i+=1){
    if(!visited[i]) topoSort(i,adj,s,visited);
  }
  // step2 transpose the graph
  vector<int> new_adj[v];
  transpose(adj,v,new_adj);
  // step 3 do a dfs on the basis of finish time
  for(int i=0;i<v;i+=1) visited[i]=false;
  // this will count number of scc
  int count=0;
  while(!s.empty()){
    int node=s.top();
    s.pop();
    if(!visited[node]){
      // dfsRev will basically traverse over a particular SCC
      dfsRev(visited,node,new_adj);
      count+=1;
    }
  }
  return count;
}
