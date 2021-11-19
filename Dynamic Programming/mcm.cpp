//gfg tested top down tc n^3 sp n^2
int dp[101][101];
int mcm(int arr[],int i,int j){
  if(i>=j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  int answer=INT_MAX;
  for(int k=i;k<j;k+=1){
    int temp=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
    answer=min(temp,answer);
  }
  return dp[i][j]=answer;
}
int matrixMultiplication(int N, int arr[]){
  memset(dp,-1,sizeof(dp));
  return mcm(arr,1,N-1);
}

// for bottom up n^3 visit https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
