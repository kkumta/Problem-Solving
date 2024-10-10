#include <bits/stdc++.h>
using namespace std;

int N, M, s, e;
vector<pair<int/*cost*/, int/*도착 도시*/>> adj[1001];
const long long INF = 10000000001;
long long dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}
	cin >> s >> e;
	
	fill(dist, dist + 1001, INF);
	pq.push(make_pair(0, s));
	dist[s] = 0;
	while (pq.size())
	{
		int here = pq.top().second;
		int cost = pq.top().first; pq.pop();
		if (dist[here] != cost) continue;
		for (pair<int, int> there : adj[here])
		{
			if (dist[there.second] > dist[here] + there.first)
			{
				dist[there.second] = dist[here] + there.first;
				pq.push(make_pair(dist[there.second], there.second));
			}
		}
	}
	
	cout << dist[e];
}