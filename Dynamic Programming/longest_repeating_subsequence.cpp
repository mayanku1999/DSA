// in gfg this code is giving segmentation fault if I add '&' in line 4 (string& str)
// gfg top down (giving TLE) tc sp n*n
int dp[1001][1001];
int lcs(string str,int m,int n){
  if(dp[m][n]!=-1) return dp[m][n];
  if(m==0||n==0) return dp[m][n]=0;
  // instead of m!=n you can also write (m-1)!=(n-1)
  if(str[m-1]==str[n-1] && m!=n) return dp[m][n]=lcs(str,m-1,n-1)+1;
  return dp[m][n]=max(lcs(str,m,n-1),lcs(str,m-1,n));
}
int LongestRepeatingSubsequence(string str){
  memset(dp,-1,sizeof(dp));
  int m = str.length();
  return lcs(str,m,m);
}
// gfg bottom up  tc sp n*n
int LongestRepeatingSubsequence(string str){
  int i,j,n=str.length(),dp[n+1][n+1];
  for(i=0;i<=n;i+=1){
    for(j=0;j<=n;j+=1){
      if(i==0||j==0) dp[i][j]=0;
      // instead of i!=j you can also write (i-1)!=(j-1)
      else if(str[i-1]==str[j-1] and i!=j) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  // for LongestRepeatingSubsequence of length 2 or more add:
  // if(dp[n][n]<2) return 0;
  // else return dp[n][n]
  return dp[n][n];
}

// print LongestRepeatingSubsequence
// not tested but it is correct
i=n;j=n;string res;
while(i>0 and j>0){
  if(s[i-1]==s[j-1] and i!=j){
    res.push_back(s[i-1]);
    i-=1;j-=1;
  }else{
    if(dp[i][j-1]>dp[i-1][j]) j-=1;
    else i-=1;
  }
}
reverse(res.begin(),res.end());
return res;
