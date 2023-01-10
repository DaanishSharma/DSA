#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
struct edge{
    int v,w;
    // operator<(edge const& other){
    //     return w<other.w;
    // }
};
vector<vector<pair<int,int>>> adj(1e5+5);
vector<int> dijkastra()
{
    vector<int> distance(N + 1, (int)1e18);
    vector<bool> processed(N + 1, 0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //   (distance,vertex)
    
    q.push({0, 1});
    distance[1] = 0;
    
    while (!q.empty())
    {
        int a = q.top().second;q.pop();
        if (processed[a])
        {
            continue;
        }
        processed[a] = true;
        for (auto u : adj[a])
        {
            int b = u.first;
            int w = u.second;
            if (distance[a] + w < distance[b])
            {
                distance[b] = w + distance[a];
                q.push({distance[b], b});
            }
        }
    }
    return distance;
}
signed main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    vector<int>distance=dijkastra();
    for (int i = 1; i < N + 1; i++)
    {
        cout << distance[i] << " ";
    }
    cout<<endl;
    return 0;
}