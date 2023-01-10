#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5+5;
vector<int> adj[MAXN]; 
bool vis[MAXN]; 
int il=0;
int n,m;
 
void dfs(int node){
    stack<int>s;
    s.push(node);
    while(!s.empty()){
        int t=s.top();
        s.pop();
        if(vis[t]){
            continue;
        }
        vis[t]=1;
        for(int&x:adj[t]){
            if(!vis[x]){
                s.push(x);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;   
        adj[x].push_back(y);
        adj[y].push_back(x);          
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans.push_back(i);
            il+=1;
            dfs(i);
        }   
    }
    cout<<il-1<<endl;   
    for(int i=0;i<il-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}
 
 
 