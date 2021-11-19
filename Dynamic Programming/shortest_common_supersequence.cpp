// for another better approach to print shortestCommonSupersequence
// https://leetcode.com/problems/shortest-common-supersequence/discuss/1101314/C%2B%2B-Different-solution-than-all-posted-here.

// [IMPORTANT] gfg top down approach to find length of shortestCommonSupersequence
// https://www.geeksforgeeks.org/shortest-common-supersequence/

// leetcode tc m*n sp (m*n)
// print length of shortestCommonSupersequence: return (m+n-dp[m][n])
string shortestCommonSupersequence(string str1, string str2) {
  int m=str1.length(),n=str2.length(),i,j;
  int dp[m+1][n+1];
  for(i=0;i<=m;i+=1){
    for(j=0;j<=n;j+=1){
      if(i==0 or j==0) dp[i][j]=0;
      else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  i=m;j=n;
  string result;
  while(i>0 and j>0){
    if(str1[i-1]==str2[j-1]){
      result.push_back(str1[i-1]);
      i-=1;
      j-=1;
    }else{
      if(dp[i-1][j]>dp[i][j-1]){
        result.push_back(str1[i-1]);
        i-=1;
      }else{
        result.push_back(str2[j-1]);
        j-=1;
      }
    }
  }
  while(i>0){
    result.push_back(str1[i-1]);
    i-=1;
  }
  while(j>0){
    result.push_back(str2[j-1]);
    j-=1;
  }
  reverse(result.begin(),result.end());
  return result;
}
