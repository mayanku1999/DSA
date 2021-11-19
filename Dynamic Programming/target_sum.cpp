// REMEMBER ARRAY VALUES CAN ALSO BE ZERO IN THIS QUESTION
// NORMAL LOGIC WILL FAIL HERE SO REMEMBER TO COVER CASES WHERE ELEMENTS CAN BE ZERO

// leetcode top down  sol tc 2^n
int arr[20][20000];
int countSubsets(vector<int>& nums, int n,int s1,int& sum,int& target){
  if(n==0){
    // dont write abs(s1-s2)
    if((s1-(sum-s1))==target) return 1;
    else return 0;
  }
  if(arr[n-1][s1]!=-1) return arr[n-1][s1];
  return arr[n-1][s1]=
  countSubsets(nums,n-1,s1+nums[n-1],sum,target)
  +
  countSubsets(nums,n-1,s1,sum,target)
  ;
}
int findTargetSumWays(vector<int>& nums, int target) {
  memset(arr,-1,sizeof(arr));
  int sum=0,n=nums.size();
  for(auto value:nums) sum+=value;
  if((sum+target)%2==1||sum<target) return 0;
  else return countSubsets(nums,n,0,sum,target);
}

// leetcode recursive sol tc 2^n
int countSubsets(vector<int>& nums,int target,int val,int i){
  if(i==nums.size()){
    if(target==val) return 1;
    else return 0;
  }
  return countSubsets(nums,target,val,i+1)+countSubsets(nums,target,val+nums[i],i+1);
}
int findTargetSumWays(vector<int>& nums, int target) {
  int sum=0;
  for(auto value:nums) sum+=value;
  if((sum+target)%2==1||sum<target) return 0;
  else return countSubsets(nums,(sum+target)/2,0,0);
}

// top down tc sp n*val where val=(target+sum)/2
// here instead of dp[i+1][val] you can also write dp[i][val]
int dp[21][1001];
int countSubsets(vector<int>& nums,int target,int val,int i){
  if(i==nums.size()){
    if(target==val) return 1;
    else return 0;
  }
  if(dp[i+1][val]!=-1) return dp[i+1][val];
  return dp[i+1][val]=countSubsets(nums,target,val,i+1)+countSubsets(nums,target,val+nums[i],i+1);
}
int findTargetSumWays(vector<int>& nums, int target) {
  int sum=0;
  memset(dp,-1,sizeof(dp));
  for(auto value:nums) sum+=value;
  if((sum+target)%2==1||sum<target) return 0;
  else return countSubsets(nums,(sum+target)/2,0,0);
}

// another leetcode recursive approach
int countSubsets(vector<int>& nums, int n,int s1,int s2,int target){
  if(n==0){
    // dont write abs(s1-s2)
    if(target==(s1-s2)) return 1;
    else return 0;
  }
  return countSubsets(nums,n-1,s1+nums[n-1],s2,target)+countSubsets(nums,n-1,s1,s2+nums[n-1],target);
}
int findTargetSumWays(vector<int>& nums, int target) {
  int s1=0,s2=0;
  return countSubsets(nums,nums.size(),s1,s2,target);
}

// bottom up tc sp n*val
int findTargetSumWays(vector<int>& nums, int target) {
  int sum=0,i,j,n=nums.size();
  for(auto value:nums) sum+=value;
  if((sum+target)%2==1||target>sum) return 0;
  int val=(sum+target)/2,dp[n+1][val+1];
  dp[0][0]=1;
  for(i=1;i<=val;i+=1) dp[0][i]=0;
  for(i=1;i<=n;i+=1){
    for(j=0;j<=val;j+=1){
      if(j<nums[i-1]) dp[i][j]=dp[i-1][j];
      else dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
    }
  }
  return dp[n][val];
}
