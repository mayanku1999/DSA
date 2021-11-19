// sort edges on the basis of weight and dont use adjacency list to store edges

// here we greedily traverse over the sorted edges and at each point we check
// whether both nodes are part of same component. If they are part of the same component
// then we wont union them because unioning them will not make an MST, it will rather make a cycle
// But if they are part of different components, then we will union them.
// So we will get minimum weights here along with mst.

// untested code tc e log e

struct node{
  int u;
  int v;
  int wt;
  node(int first,int second,int weight){
    u=first;
    v=second;
    wt=weight;
  }
};
bool comp(node a,node b){
  return a.wt<b.wt;
}
int findParent(int node,vector<int>& parent){
  if(node==parent[node]) return node;
  // path compresion
  return parent[node]=findParent(parent[node],parent);
}
void union(int u,int v,vector<int> &parent, vector<int> &rank){
  u=findParent(u,parent);
  v=findParent(v,parent);
  if(rank[u]<rank[v]){
    parent[u]=v;
  }else if(rank[u]>rank[v]){
    parent[v]=u;
  }else{
    parent[u]=v;
    rank[v]+=1;
  }
}
int main(){
  // n is no of nodes, m is no of edges
  int n,m; cin>>n>>m;
  vector<node> edges;
  for(int i=0;i<m;i+=1){
    int u,v,wt; cin>>u>>v>>wt;
    edges.push_back(node(u,v,wt));
  }
  // sort the edges based on the wt
  sort(edges.begin(),edges.end(),comp);
  vector<int> parent(n);
  for(int i=0;i<n;i+=1) parent[i]=i;
  vector<int> rank(n,0);
  // this will store the mst
  vector<pair<int,int>> mst;
  int min_cost=0;
  // linearly traverse over the sorted edges
  for(auto it: edges){
    // check whether both the nodes u and v belong to the same component or not
    // if both parent are same, then u and v belong to the same component
    // if parents are different, then we will do a union on both the nodes u and v
    if(findParent(it.u,parent)!=findParent(it.v,parent)){
      min_cost+=it.wt;
      mst.push_back({it.u,it.v});
      union(it.u,it.v,parent,rank);
    }
  }
  cout<<"cost: "<<min_cost<<endl;
  for(auto it:mst) cout<<it.first<<" -> "<<it.second<<endl;
}
