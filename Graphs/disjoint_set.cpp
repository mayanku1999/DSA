// union by rank and path compression
// https://www.youtube.com/watch?v=3gbO7FDYNFQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25
// tc is constant

int parent[100000];
int rank[100000];
void makeSet(int n){
  for(int i=1;i<=n;i+=1){
    parent[i]=i;
    rank[i]=0;
  }
}
int findParent(int node){
  if(node==parent[node]){
    return node;
  }
  // 7->6->4->2->5 here parent of every node is ultimately 5 so we will compress path
  // path compression
  return parent[node]=findParent(parent[node]);
}
void union(int u,int v){
  u=findParent(u);
  v=findParent(v);
  if(rank[u]<rank[v]){
    parent[u]=v;
  }else if(rank[u]>rank[v]){
    parent[v]=u;
  }else{
    // you can also write parent[v]=u; rank[u]+=1;
    parent[u]=v;
    rank[v]+=1;
  }
}
void main(){
  int n; cin>>n;
  // n is number of nodes
  makeSet(n);
  // m is number of union operations
  int m; cin>>m;
  while(m--){
    int u,v; cin>>u,v;
    union(u,v);
  }
  // to check whether two nodes are part of the same componenet or not
  if(findParent(2)!=findParent(3)){
    cout<<"Different component";
  }else{
    cout<<"Same component";
  }
}
