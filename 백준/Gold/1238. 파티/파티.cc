#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, X, ans;
vector<pair<int, int>> adj[1001], rAdj[1001];
int dist[1001], ret[1001];
priority_queue<pair<int, int>> pq;

int main()
{
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
		rAdj[b].push_back(make_pair(c, a));
	}
	
	// 1. 각 마을에서 X 마을로 가는 데 걸리는 시간 구하기 
	fill(dist, dist + 1001, INF);
	dist[X] = 0;
	pq.push(make_pair(0, X));
	while (pq.size())
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		
		if (dist[here] != cost) continue;
		for (auto there : rAdj[here])
		{
			if (dist[there.second] > dist[here] + there.first)
			{
				dist[there.second] = dist[here] + there.first;
				pq.push(make_pair(dist[there.second], there.second));
			}
		}
	}
	
	for (int i = 1; i <= N; i++)
		ret[i] = dist[i];
		
	// 2. X 마을에서 각 마을로 가는 데 걸리는 시간 구하기
	fill(dist, dist + 1001, INF);
	dist[X] = 0;
	pq.push(make_pair(0, X));
	while (pq.size())
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		
		if (dist[here] != cost) continue;
		for (auto there : adj[here])
		{
			if (dist[there.second] > dist[here] + there.first)
			{
				dist[there.second] = dist[here] + there.first;
				pq.push(make_pair(dist[there.second], there.second));
			}
		}
	}	
	
	for (int i = 1; i <= N; i++)
		ret[i] += dist[i];
		
	// 3. 가장 오래 걸리는 학생의 소요시간 구하기
	for (int i = 1; i <= N; i++)
		ans = max(ans, ret[i]);
		
	cout << ans;
}