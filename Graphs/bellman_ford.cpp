// go to 18:50 for intuition https://www.youtube.com/watch?v=75yC1vbS8S8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29
// 1-2-3-4-5 (here we will run bf algo 4 times only)
// bellman ford
// it will fail in both udg and dg when we have negative cyles in the graph
// but it will help us detecting the negative cycle.
// for bellman ford in udg, convert it into dg using bi-directional edges and then apply it.
// if there is any edge with negative weight in udg then algo will fail because
// then we will have a negative cycle.
// for bellman ford in dg, just follow the procedure

// relax all edges exactly n-1 times (n = no of nodes) because thats the longest path we can have
// relaxation means if(d[u]+w<d[v]) d[v]=d[u]+w;
// After exactly n-1 times we will have our answer in distance vector
// try relaxing it the nth time:
// if the distance vector reduces then we have a negative cycle
// if there is no negative cycle then the distance vector wont reduce the nth time

// gfg tested tc n*e(edges) sp n(distance)
int isNegativeWeightCycle(int n, vector<vector<int>> edges){
  // dont give INT_MAX as we are relaxing so dist[u] + weight may go out of bounds
  vector<int> distance(n,100000000);
  distance[0]=0;
  for(int j=1;j<n;j+=1){
    for(int i=0;i<edges.size();i+=1){
      int u=edges[i][0];
      int v=edges[i][1];
      int weight=edges[i][2];
      if(distance[u]+weight<distance[v]){
        distance[v]=distance[u]+weight;
      }
    }
  }
  // relaxing for the nth time to find negative edge
  for(int i=0;i<edges.size();i+=1){
    int u=edges[i][0];
    int v=edges[i][1];
    int weight=edges[i][2];
    if(distance[u]+weight<distance[v]){
      return 1;
    }
  }
  return 0;
}
