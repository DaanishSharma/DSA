#include <bits/stdc++.h>
using namespace std;

bool visited[(int)1e5 + 5];
int depth[(int)1e5 + 5];
vector<int> adj[(int)1e5 + 5];
int N, M;
int dfs(int n) {
    if(visited[n])  return depth[n];
    if(n==N){
        return 1;
    }
    visited[n]=1;
    int mx=INT_MIN;
    for(int&x : adj[n]){
        mx=max(mx,1+dfs(x));
    }
    depth[n]=mx;

    return mx;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
    depth[N]=1;
    if(dfs(1)<0){
        cout<<"IMPOSSIBLE\n";
    }
    cout<<depth[1]<<endl;
    stack<int>s;
    s.push(1);
    while(!s.empty()){
        int top = s.top();s.pop();
        cout<<top<<" ";
        if(top==N)  break;
        for(int&x: adj[top]){
            if(depth[x]==(depth[top]-1)){
                s.push(x);
            }
        }
    }

}