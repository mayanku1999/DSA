// didnt test it
string longestCommonSubsequence(string text1, string text2) {
  int m=text1.size(),n=text2.size(),i,j;
  int dp[m+1][n+1];
  for(i=0;i<=m;i+=1){
    for(j=0;j<=n;j+=1){
      if(i==0||j==0) dp[i][j]=0;
      else if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  //dp[m][n] will have length of the lcs
  i=m;j=n;
  string s;
  while(i>0 and j>0){
    if(text1[i-1]==text2[j-1]){
      s.push_back(text1[i-1]);
      i-=1;j-=1;
    }else{
      if(dp[i][j-1]>dp[i-1][j]) j-=1;
      else i-=1;
    }
  }
  reverse(s.begin(),s.end());
  return s;
}
