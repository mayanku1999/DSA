tc: o(v+e)
sp: o(v)+o(v)+o(v+e) // visited, queue and adj list

nodes are from 1 to v

void bfs(vector<int> adj_list[],int i,vector<bool> visited){
  queue<int> q;
  q.push(i);
  visited[i]=true;
  while(!q.empty()){
    int p=q.front();
    q.pop();
    cout<<p<<" ";
    for(auto it:adj_list[p]){
      if(!visited[it]){
        q.push(it);
        visited[it]=true;
      }
    }
  }
}

vector<bool> visited(v+1,false);
// disconnected components will be taken care of
for(i=1;i<=v;i+=1){
  if(!visited[i]){
    bfs(adj_list,i,visited);
  }
}
