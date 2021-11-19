// EXPLANATION: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/discuss/355894/Python-DP-with-memoization-explained

// leetcode recursive tc f^d
int findWays(int d, int f, int target){
  if(target==0 and d==0) return 1;
  else if(target==0 or d==0) return 0;
  int count=0;
  for(int i=1;i<=f;i+=1){
    count+=findWays(d-1,f,target-i);
  }
  return count;
}
int numRollsToTarget(int d, int f, int target) {
  return findWays(d,f,target);
}

// top down using dp array tc f*d*target sp d*target
int mod=pow(10,9)+7,dp[31][1001];
int findWays(int d, int f, int target){
  if(target==0 and d==0) return 1;
  else if(target<=0 or d==0) return 0;
  else if(dp[d][target]!=-1) return dp[d][target];
  int count=0;
  for(int i=1;i<=f;i+=1){
    count=(count+findWays(d-1,f,target-i))%mod;
  }
  return dp[d][target]=count;
}
int numRollsToTarget(int d, int f, int target){
  memset(dp,-1,sizeof(dp));
  return findWays(d,f,target);
}

// top down using map tc f*d*target sp d*target
int mod=pow(10,9)+7;
map<string,int> mp;
int findWays(int d, int f, int target){
  if(target==0 and d==0) return 1;
  else if(target<=0 or d==0) return 0;
  string key=to_string(d)+" "+to_string(target);
  if(mp.count(key)==1) return mp[key];
  int count=0;
  for(int i=1;i<=f;i+=1){
    count=(count+findWays(d-1,f,target-i))%mod;
  }
  return mp[key]=count;
}
int numRollsToTarget(int d, int f, int target){
  memset(dp,-1,sizeof(dp));
  return findWays(d,f,target);
}






class Solution {
public:
    int solve(int D,int F,int S,int s,vector<vector<int>>&dp){
    if(D==0){
        if(s==S)return 1;
        else return 0;
    }
    if(s>S)return 0;
    if(dp[D][s]!=-1)return dp[D][s];
    long long int ans=0;
    for(int i=1;i<=F;i++){
       // if(s+i<=S)
        ans+=solve(D-1,F,S,s+i,dp);
       // else break;
    }
    return dp[D][s] = ans%1000000007;
}
    int numRollsToTarget(int d, int f, int s) {
        int sum=0;
    vector<vector<int>> dp(d+1,vector<int>(10000,-1));
    return solve(d,f,s,sum,dp);
    }
};