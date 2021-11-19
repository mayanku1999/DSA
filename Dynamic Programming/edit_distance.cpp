// leetcode recursive tc 3^n
int findMinimumOperations(string word1,int m,string word2,int n){
  // insert all characters to word1
  if(m==0) return n;
  // remove all characters from word1
  else if(n==0) return m;
  else if(word1[m-1]==word2[n-1])
  return findMinimumOperations(word1,m-1,word2,n-1);
  else return 1+min(
    // replace
    findMinimumOperations(word1,m-1,word2,n-1),
    // deletion
    findMinimumOperations(word1,m-1,word2,n),
    // insertion
    findMinimumOperations(word1,m,word2,n-1)
  );
}
int minDistance(string word1, string word2) {
  return findMinimumOperations(word1,word1.length(),word2,word2.length());
}

// leetcode top down tc sp n*n
int dp[500][500];
int findMinimumOperations(string& word1,int m,string& word2,int n){
  // insert all characters to word1
  if(m==0) return n;
  // remove all characters from word1
  else if(n==0) return m;
  else if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
  else if(word1[m-1]==word2[n-1])
  return dp[m-1][n-1]=findMinimumOperations(word1,m-1,word2,n-1);
  else return dp[m-1][n-1]=1+min(
    // replace
    findMinimumOperations(word1,m-1,word2,n-1),
    min(
      // deletion
      findMinimumOperations(word1,m-1,word2,n),
      // insertion
      findMinimumOperations(word1,m,word2,n-1)
    )
  );
}
int minDistance(string word1, string word2) {
  memset(dp,-1,sizeof(dp));
  return findMinimumOperations(word1,word1.length(),word2,word2.length());
}

// leetcode bottom up tc sp n*n
// deletion dp[i-1][j], insertion dp[i][j-1], replace dp[i-1][j-1]
int minDistance(string word1, string word2) {
  int i,j,m=word1.length(),n=word2.length(),dp[m+1][n+1];
  for(i=0;i<=m;i+=1){
    for(j=0;j<=n;j+=1){
      if(i==0) dp[i][j]=j;
      else if(j==0) dp[i][j]=i;
      else if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
      else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
    }
  }
  return dp[m][n];
}
