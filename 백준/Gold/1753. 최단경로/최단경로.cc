#include <bits/stdc++.h>
using namespace std;

// 시작점에서 다른 모든 정점으로의 최단 경로
// 모든 간선의 가중치는 자연수
// -> 다익스트라 

int V, E, K;
long long INF = 10987654321;
vector<pair<long long/*비용*/, int/*도착 도시*/>> adj[20001];
long long dist[20001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int main()
{
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}
	
	fill(dist, dist + 20001, 10987654321);
	dist[K] = 0;
	pq.push(make_pair(0, K));
	while (pq.size())
	{
		long long cost = pq.top().first;
		int here = pq.top().second; pq.pop();
		
		if (cost != dist[here]) continue;
		for (pair<long long, int> there : adj[here])
		{
			if (dist[there.second] > dist[here] + there.first)
			{
				dist[there.second] = dist[here] + there.first;
				pq.push(make_pair(dist[there.second], there.second));
			}
		}
	}
	
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}