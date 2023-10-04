#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

#define cost first
#define v second

const int INF = 100'000'000;

int n, m, start, finish;
vector<pair<int, int>> adj[1001]; // cost, v 순서
int d[1001];
int parent[1001];

void Dijikstra(int start)
{
	fill(d, d + n + 1, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[start] = 0;
	pq.push(make_pair(d[start], start));
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (d[cur.v] != cur.cost) continue;
		for (pair<int, int> next : adj[cur.v])
		{
			if (d[next.v] <= d[cur.v] + next.cost) continue;
			d[next.v] = d[cur.v] + next.cost;
			pq.push(make_pair(d[next.v], next.v));
			parent[next.v] = cur.v;
		}
	}

	cout << d[finish] << endl;

	vector<int> route;

	int cur = finish;
	route.push_back(cur);
	while (cur != start)
	{
		cur = parent[cur];
		route.push_back(cur);
	}
	reverse(route.begin(), route.end());

	cout << route.size() << endl;
	for (int v : route)
		cout << v << " ";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		adj[v1].push_back(make_pair(c, v2));
	}

	cin >> start >> finish;

	Dijikstra(start);
}