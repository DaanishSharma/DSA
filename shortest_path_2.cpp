#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXD = 1e18;
int N, M, Q;
signed main()
{
    cin >> N >> M >> Q;
    vector<vector<int>> distance(N + 1, vector<int>(N + 1, MAXD));
    for(int i=0;i<=N;i++){
        distance[i][i]=0;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        distance[a][b] = min(w,distance[a][b]);
        distance[b][a] = min(w,distance[b][a]);
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int s, d;
        cin >> s >> d;
        if (distance[s][d] != (MAXD))
        {
            cout << distance[s][d] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}