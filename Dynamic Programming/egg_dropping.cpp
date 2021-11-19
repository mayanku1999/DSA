// tc of recursive is f*(2^min(e,f))

// gfg top down tc e*f*f sp e*f
// this will give tle on leetcode
int dp[201][201];
int eggDropUtil(int e, int f){
  if(f==0||f==1||e==1) return f;
  if(dp[e][f]!=-1) return dp[e][f];
  int answer=INT_MAX;
  for(int i=1;i<=f;i+=1){
    int attempts=1+max(eggDropUtil(e-1,i-1),eggDropUtil(e,f-i));
    answer=min(attempts,answer);
  }
  return dp[e][f]=answer;
}
int eggDrop(int e, int f){
  memset(dp,-1,sizeof(dp));
  return eggDropUtil(e,f);
}

// leetcode top down tc e*f*logf sp e*f
int dp[101][10001];
int superEggDropUtil(int e, int f) {
  if(e==1||f==0||f==1) return f;
  int low=1,high=f,mid,answer=INT_MAX;
  if(dp[e][f]!=-1)return dp[e][f];
  while(low<=high){
    mid=(low+high)/2;
    int down=superEggDropUtil(e-1,mid-1);
    int up=superEggDropUtil(e,f-mid);
    if(up>down) low=mid+1;
    else high=mid-1;
    int attempts=1+max(up,down);
    answer=min(attempts,answer);
  }
  return dp[e][f]=answer;
}
int superEggDrop(int e, int f) {
  memset(dp,-1,sizeof(dp));
  return superEggDropUtil(e,f);
}
