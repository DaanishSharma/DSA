#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5+5;
vector<int> adj[MAXN]; 
bool vis[MAXN]; 
vector<int>result;
stack<int>s;
int n,m;
 
void dfs(int node,int parent){
    vis[node]=true;
    s.push(node);
    for(auto x:adj[node]){
        if(x!=parent){
            if(!vis[x]){
                dfs(x,node);
            }
            else if(size(result)==0){
                result.push_back(x);
                while (!s.empty() and (s.top()!=x))
                {
                    result.push_back(s.top());
                    s.pop();
                }
                result.push_back(x);
            }
        }
    }
    if(s.size()>0 and s.top()==node){
        s.pop();
    }  
 
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;   
        adj[x].push_back(y);
        adj[y].push_back(x);          
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])
            dfs(i,-1);
        if(result.size()!=0){
            cout<<result.size()<<endl;
            for(int&x :result){
                cout<<x<<" ";
            }
            cout<<endl;
            return 0;
        }
        
    }
    cout<<"IMPOSSIBLE\n";   
    return 0;
}
 
 