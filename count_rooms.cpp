#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='#'){
                vis[i][j]=1;
            }
        }
    }
    long long rooms=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                rooms+=1;
                stack<vector<int>>q;
                q.push({i,j});
                while(!q.empty()){
                    vector<int>top=q.top();
                    // cout<<top[0]<<" "<<top[1]<<endl;
                    vis[top[0]][top[1]]=1;
                    q.pop();
                    vector<vector<int>>ngh={{top[0]+1,top[1]},{top[0],top[1]+1},{top[0]-1,top[1]},{top[0],top[1]-1}}; 
                    for(vector<int>&v:ngh){
                        if(v[0]>=0 && v[1]>=0 && v[0]<n && v[1]<m && (vis[v[0]][v[1]]==0)){
                            q.push(v);
                        }
                    }                   
                }
                // cout<<"******************\n";
            }
        }
    }
    cout<<rooms<<endl;
    return 0;
}
 
 
 