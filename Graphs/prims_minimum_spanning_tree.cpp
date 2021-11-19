given an undirected,weighted(+ve) and connected graph, a minimum spanning tree of the graph
is a tree with n nodes and n-1 edges such that each node is conected with
every other node and the weights of the edges is as min as possible

// prim's algo brute force
// tc v*v sp(n+n+n) mstset,parent,min_weight
int spanningTree(int v, vector<pair<int,int>> adj[]){
  vector<bool> mstSet(v,false);
  vector<int> parent(v,-1);
  vector<int> min_weight(v,INT_MAX);
  parent[0]=-1;
  min_weight[0]=0;
  for(int i=0;i<v-1;i+=1){
    int min=INT_MAX,u;
    for(int j=0;j<v;j+=1){
      if(mstSet[j]==false and min_weight[j]<min){
        min=min_weight[j];
        u=j;
      }
    }
    //traversing the neighbours of u
    for(auto j:adj[u]){
      int node=j.first;
      int wt=j.second;
      if(mstSet[node]==false and wt<min_weight[node]){
        min_weight[node]=wt;
        parent[node]=u;
      }
    }
    /*write this commented code in gfg, then this code will run
    for(auto j:adj[u]){
      if(mstSet[j[0]]==false && j[1]<min_weight[j[0]]){
        min_weight[j[0]]=j[1];
        parent[j[0]]=u;
      }
    }*/
    mstSet[u]=true;
  }
  // gfg question asked to return min weight so i added whole min_weight
  // notice we are starting from 1 because weight from 0 will be 0
  int sum=0;
  for(int i=1;i<v;i+=1){
    sum+=min_weight[i];
  }
  return sum;
}

// optimized prim's tc (v+e)logv
int spanningTree(int v, vector<pair<int,int>> adj[]){
  vector<bool> mstSet(v,false);
  vector<int> parent(v,-1);
  vector<int> min_weight(v,INT_MAX);
  parent[0]=-1;
  min_weight[0]=0;
  //min heap will have min ele at the top
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  //{weight,index}
  pq.push({0,0});
  while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();
    //traversing the neighbours of u
    for(auto j:adj[u]){
      int node=j.first;
      int wt=j.second;
      if(mstSet[node]==false and wt<min_weight[node]){
        min_weight[node]=wt;
        parent[node]=u;
        pq.push({wt,node});
      }
    }
    /*write this commented code in gfg, then this code will run
    for(auto j:adj[u]){
      if(mstSet[j[0]]==false && j[1]<min_weight[j[0]]){
        parent[j[0]]=u;
        min_weight[j[0]]=j[1];
        pq.push({j[1],j[0]});
      }
    }*/
    mstSet[u]=true;
  }
  // gfg question asked to return min weight so i added whole min_weight
  // notice we are starting from 1 because weight from 0 will be 0
  int sum=0;
  for(int i=1;i<v;i+=1){
    sum+=min_weight[i];
  }
  return sum;
}
