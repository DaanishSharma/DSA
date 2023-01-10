#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[(int)1e5 + 5], on_stack[(int)1e5 + 5];
vector<int> adj[(int)1e5 + 5];
vector<int> cycle;
int N, M;
void dfs(int n) {
	visited[n]=on_stack[n]=1;
    for(int&x : adj[n]){
        if(!visited[x]){
            dfs(x);
        }
        else if(on_stack[x]){
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
    }
    on_stack[n]=0;
    cycle.push_back(n);
}
int main()
{
	// take input, etc
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1;i <= N; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
	if(cycle.empty())
		cout << "IMPOSSIBLE";
	else {
		reverse(cycle.begin(), cycle.end());
		for(int n : cycle) cout << n << " ";
        }
}