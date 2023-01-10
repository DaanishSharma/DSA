#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
bool visited[(int)1e5 + 5];
unsigned long long ways[(int)1e5 + 5];
vector<int> adj[(int)1e5 + 5];
int N, M;
unsigned long long dfs(unsigned long long  n) {
    if(visited[n])  return ways[n];
    if(n==N){
        return 1;
    }
    visited[n]=1;
    for(int&x : adj[n]){
        ways[n]=(ways[n]+dfs(x))%mod;
    }
    return ways[n];
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
    cout<<dfs(1)%mod<<endl;
}