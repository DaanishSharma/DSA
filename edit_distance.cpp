#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,n;
  string u,v;
  cin>>u>>v;
  m = u.size();
  n = v.size();
  //transform u into v 
  int dp[m+1][n+1];
  for(int i=0;i<m+1;i++){
    dp[i][n] = m - i;      
  }
  for(int i=0;i<n+1;i++){
    dp[m][i] = n - i;      
  }
  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      if(u[i]==v[j]){
        dp[i][j]=dp[i+1][j+1]; 
      }
      else{
        dp[i][j]=1+min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
      }
    }
  }
  cout<<dp[0][0]<<endl;
 int i,j;
 i=0;
 j=0;
 while(i<m&&j<n){
    if(u[i]==v[j]){
      i+=1;
      j+=1;
    }
    else if(min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]})==dp[i+1][j+1]){
      cout<<"substitute "<<u[i]<<" with"<<v[j]<<endl;
      i++;
      j++;
    }
    else if(min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]})==dp[i+1][j]){
       cout<<"delete "<<u[i]<<endl;
       i++;
    }
    else if(min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]})==dp[i][j+1]){
       cout<<"insert "<<v[j]<<endl;
       j++;
    }
  }
  return 0;
}
