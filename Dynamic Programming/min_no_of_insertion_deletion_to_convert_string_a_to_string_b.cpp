// leetcode tc sp m*n. it is just the lcs. You can also write bottom up or recursion
// this question is asking total deletions to be done from both the strings thats y m+n-2*len
// if question will ask to convert given string s1 to another given string s2
// then no of deletions will be m-len and insertions will be n-len
int dp[501][501];
int lcs(string word1, string word2,int m,int n){
  if(n==0||m==0) return 0;
  if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
  else if(word1[m-1]==word2[n-1]) return dp[m-1][n-1]=1+lcs(word1,word2,m-1,n-1);
  else return dp[m-1][n-1]=max(lcs(word1,word2,m,n-1),lcs(word1,word2,m-1,n));
}
int minDistance(string word1, string word2) {
  int m=word1.length(),n=word2.length();
  memset(dp,-1,sizeof(dp));
  int len=lcs(word1,word2,m,n);
  return m+n-(2*len);
}
