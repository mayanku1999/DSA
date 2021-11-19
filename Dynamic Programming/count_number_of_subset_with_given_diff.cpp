// i didnt test anything here. This question is same as target sum
// please refer target sum

int countSubsets(vector<int>& nums, int n,int s1,int s2,int diff){
  if(n==0){
    if(diff==(s1-s2)) return 1;
    else return 0;
  }
  return countSubsets(nums,n-1,s1+nums[n-1],s2,diff)+countSubsets(nums,n-1,s1,s2+nums[n-1],target);
}
int findTargetSumWays(vector<int>& nums, int diff) {
  int s1=0,s2=0;
  return countSubsets(nums,nums.size(),s1,s2,diff);
}

//top down
int dp[21][1001];
int countSubsets(vector<int>& nums, int n,int s1,int sum){
  if(n==0){
    if(sum==s1) return 1;
    else return 0;
  }
  if(dp[n-1][s1]!=-1) return dp[n-1][s1];
  return dp[n-1][s1]=countSubsets(nums,n-1,s1+nums[n-1],sum)+countSubsets(nums,n-1,s1,sum);
}
// target here is actually the given difference
int findTargetSumWays(vector<int>& nums, int target) {
  int s1=0,sum=0;
  for(auto it:nums) sum+=it;
  memset(dp,-1,sizeof(dp));
  if((sum+target)%2==1||sum<target) return 0;
  return countSubsets(nums,nums.size(),s1,(sum+target)/2);
}

// find bottom up in target sum question
