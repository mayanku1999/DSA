// here we will first find the topological sort
// and then use the values in stack to get the answer
// here adj list will be of the type pair<int,int> to store adjacent nodes as well as weights
// because of Topological Ordering, we will already know which nodes will come after the current node
// i didnt test this
// tc 2*(v+e) sp 3n(visited,stack,distance)

void findTopoSort(vector<bool>& visited, vector<pair<int,int>> adj[],int start,stack<int>& s){
  visited[start]=true;
  for(auto it:adj[start]){
    if(!visited[it.first]){
      findTopoSort(visited,adj,it.first,s);
    }
  }
  s.push(start);
}

void shortestPath(int source,int v,vector<pair<int,int>> adj[]){
  // we will find the topological sort
  stack<int> s;
  vector<bool> visited(v,false);
  for(int i=0;i<v;i+=1){
    if(!visited[i]) findTopoSort(visited,adj,i,s);
  }
  vector<distance> distance(v,INT_MAX);
  distance[source]=0;
  while(!s.empty()){
    int node=s.top();
    s.pop();
    // if the node's distance is int max this means that it is unreachable from source
    // so we will let it remaine int max
    // if the node is reachable then it wont be int max
    if(distance[node]!=INT_MAX){
      for(auto it: adj[node]){
        if(distance[it.first]>distance[node]+it.second){
          distance[it.first]=distance[node]+it.second;
        }
      }
    }
  }
  for(i=0;i<v;i+=1){
    if(distance[i]==INT_MAX) cout<<"INF"<<" ";
    else cout<<distance[i]<<" ";
  }
}
