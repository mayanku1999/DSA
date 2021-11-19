// leetcode top down sp tc n1*n2. dont forget to add '&''
int dp[1001][1001];
int findLCS(string& text1,int n1,string& text2,int n2){
  if(n1==0||n2==0) return 0;
  if(dp[n1-1][n2-1]!=-1) return dp[n1-1][n2-1];
  else if(text1[n1-1]==text2[n2-1]) return dp[n1-1][n2-1]=1+findLCS(text1,n1-1,text2,n2-1);
  else return dp[n1-1][n2-1]=max(findLCS(text1,n1-1,text2,n2),findLCS(text1,n1,text2,n2-1));
}
int longestCommonSubsequence(string text1, string text2) {
  memset(dp,-1,sizeof(dp));
  int n1=text1.size(),n2=text2.size();
  return findLCS(text1,n1,text2,n2);
}
// leetcode bottom up tc sp m*n
int longestCommonSubsequence(string text1, string text2) {
  int m=text1.size(),n=text2.size(),i,j;
  int dp[m+1][n+1];
  for(i=0;i<=m;i+=1){
    for(j=0;j<=n;j+=1){
      if(i==0||j==0) dp[i][j]=0;
      else if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  return dp[m][n];
}
