#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[(int)1e5 + 5], on_stack[(int)1e5 + 5];
vector<int> adj[(int)1e5 + 5];
vector<int> cycle;
int N, M;
bool dfs(int n) {
	visited[n]=on_stack[n]=1;
    for(int u : adj[n]){
        if(on_stack[u]){
            cycle.push_back(n);
            on_stack[u]=on_stack[n]=0;
            return 1;
        }
        else if(!visited[u]){
            if(dfs(u)){  //haje looking back (backtacking)
                if(on_stack[n]){
                    on_stack[n]=0;
                    cycle.push_back(n);
                    return 1;
                }
                else{   //backtracking complete
                    cycle.push_back(n);
                    return 0;
                }
            }
            else if(!cycle.empty()){
                return false;
            }
        }
    }
    on_stack[n]=0;
    return 0;
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
	for (int i = 1; cycle.empty() && i <= N; i++)
		dfs(i);
	if(cycle.empty())
		cout << "IMPOSSIBLE";
	else {
		reverse(cycle.begin(), cycle.end());
		cout << cycle.size() + 1 << "\n";
		for(int n : cycle) cout << n << " ";
		cout << cycle.at(0);
	}
}