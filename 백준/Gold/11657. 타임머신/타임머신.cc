#include <bits/stdc++.h>
using namespace std;

int N, M;
long long INF = 987654321;
vector<pair<int, int>> adj[501];
long long dist[501];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back(make_pair(C, B));
	}	
	
	fill(dist, dist + 501, INF);
	dist[1] = 0;	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto there : adj[j])
			{
				if (dist[j] != INF && dist[there.second] > dist[j] + there.first)
				{					
					dist[there.second] = dist[j] + there.first;

					if (i == N)
					{
						cout << -1;
						return 0;
					}					
				}
			}
		}
	}
	
	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == INF) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
}