// Dijkstra Algorithm - Single Source Shortest Path
// we cannot apply the logic of shortest_path_in_undirected_graph_with_unit_weights.cpp
// there we had weights as 1 only but here we have postive weights of any value
// so simple bfs with queue worked there but it will fail here

// dijkstra won't work on negative edges

// i didnt test this code. in this code we have an undirected graph with weights
// adj list contains {node,weight} and we are using a min heap so that we
// get the min distances at the top
// tc (v+e)logv
void dijkstra(vector<pair<int,int>> adj[],int v,int source){
  vector<int> distance(v,INT_MAX);
  distance[source]=0;
  // declaring a min heap
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  //{distance,node}
  pq.push({0,source});
  while(!pq.empty()){
    int dist=pq.front().first;
    int node=pq.front().second;
    pq.pop();
    for(auto it: adj[node]){
      // instead of distance[node] i can also write dist
      if(distance[it.first]>distance[node]+it.second){
        distance[it.first]=distance[node]+it.second;
        pq.push({distance[it.first],it.first});
      }
    }
  }
  print distance;
}
