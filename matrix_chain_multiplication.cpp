#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>r(n,0),c(n,0);
  for(int i=0;i<n;i++){
    cin>>r[i]>>c[i];
  }
  //cost[i][j] is minimum number of operations for mcm i to j 
  int cost[n][n];
  memset(cost,0,sizeof(cost));
  for(int i=n-2;i>=0;i--){
    for(int j=i+1;j<n;j++){
      int mn = INT_MAX;
      for(int k=i;k<j;k++){
        mn = min(mn,r[i]*c[k]*c[j]+cost[i][k]+cost[k+1][j]);
      }
      cost[i][j] = mn; 
    }
  }
  
  cout<<cost[0][n-1];
  return 0;
}
