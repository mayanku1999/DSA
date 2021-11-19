// i didnt test this. Here we have to print the shortest path to all nodes from source
// assumption: distance between two nodes is 1
// we can get the shortest path by using BFS
// tc v+e sp n+n(queue,distance)

void bfs(int adj[],int v,int source){
  queue<int> q;
  vector<int> distance(v,10000000);
  q.push(source);
  distance[source]=0;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto it:adj[node]){
      if(distance[it]>distance[node]+1){
        distance[it]=distance[node]+1;
        q.push(it);
      }
    }
  }
  print distance;
}

// you can print the shortest path by using a parent vector
// initially parent[every node]=-1;
// write parent[it]=node inside the if block
// after while loop is over, run the below code
vector<int> path;
path.push_back(dest);
int i=dest;
while(parent[i]!=-1){
  path.push_back(parent[i]);
  i=parent[i];
}
reverse(path.begin(),path.end());
