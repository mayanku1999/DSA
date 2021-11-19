// gfg recursice tc 3^(n+m) sp o(m+n)
int lcsUtil(string s1, string s2, int n, int m,int count){
  if(n==0||m==0) return count;
  else if(s1[n-1]==s2[m-1]) count=lcsUtil(s1,s2,n-1,m-1,count+1);
  return count=max(count,max(lcsUtil(s1,s2,n-1,m,0),lcsUtil(s1,s2,n,m-1,0)));
}
int longestCommonSubstr (string s1, string s2, int n, int m){
  int count=0;
  return lcsUtil(s1,s2,n,m,count);
}

// leetcode tested top down tc sp n*m
// you can change dp[n][m] to dp[n-1][m-1]
int dp[1001][1001],count;
int lcss(string& s1, string& s2, int n, int m){
  if(n==0||m==0) return 0;
  if(dp[n][m]!=-1) return dp[n][m];
  lcss(s1,s2,n-1,m);
  lcss(s1,s2,n,m-1);
  if(s1[n-1]==s2[m-1]){
    dp[n][m]=lcss(s1,s2,n-1,m-1)+1;
    count=max(count,dp[n][m]);
    return dp[n][m];
  }
  return dp[n][m]=0;
}
int longestCommonSubstr (string s1, string s2, int n, int m){
  memset(dp,-1,sizeof(dp));
  count=0;
  lcss(s1,s2,n,m);
  return count;
}

// gfg bottom up tc sp n*m
int longestCommonSubstr (string s1, string s2, int n, int m){
  // take result 0 if the length of substring is 0
  int i,j,dp[n+1][m+1],result=0;
  for(i=0;i<=n;i+=1){
    for(j=0;j<=m;j+=1){
      if(i==0||j==0) dp[i][j]=0;
      else if(s1[i-1]==s2[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
        result=max(result,dp[i][j]);
        // 1) for printing lcss do this
        // if (result<dp[i][j]){
        //   result=dp[i][j]
        //   row=i
        //   col=j
        // }
      }
      else dp[i][j]=0;
    }
  }
  // 2) for printing lcss do this
  // string answer;
  // if(result==0) return answer;
  // while(dp[row][col]!=0){
  //   answer.push_back(s1[row-1]);
  //   row-=1;col-=1
  // }
  // return reverse of answer;
  return result;
}
