#include <bits/stdc++.h>
using namespace std;

const long long INF = 10987654321;
int TC, N, M, W, S, E, T;
long long dist[501];
vector<pair<int, int>> adj[501];

bool go()
{
	cin >> N >> M >> W;
	for (int i = 1; i <= 500; i++)
		adj[i].clear();
	for (int j = 0; j < M; j++)
	{
		cin >> S >> E >> T;
		adj[S].push_back(make_pair(T, E));
		adj[E].push_back(make_pair(T, S));
	}
	for (int j = 0; j < W; j++)
	{
		cin >> S >> E >> T;
		adj[S].push_back(make_pair(-T, E));
	}
	
	fill(dist, dist + 501, 0);
	for (int j = 1; j <= N; j++)
	{
		for (int k = 1; k <= N; k++)
		{
			for (auto there : adj[k])
			{
				if (dist[there.second] > dist[k] + there.first)
				{
					dist[there.second] = dist[k] + there.first;
					
					if (j == N)
						return true;
				}
			}
		}
	}	
	
	return false;
}

int main()
{
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		if (go())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}