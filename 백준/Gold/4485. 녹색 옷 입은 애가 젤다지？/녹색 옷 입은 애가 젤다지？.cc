#include <bits/stdc++.h>
using namespace std;

struct cmp
{
	bool operator()(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
	{
		return a.first > b.first;
	}
};

int N, cnt = 1;
vector<pair<int, pair<int, int>>> adj[126][126];
int dist[126][126];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	while (true)
	{
		cin >> N;
		if (N == 0) return 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				adj[i][j].clear();
				
		fill(&dist[0][0], &dist[0][0] + 126 * 126, 987654321);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a;
				cin >> a;
				
				if (i == 0 && j == 0) dist[i][j] = a;
				
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && ny < N && nx >= 0 && nx < N)
						adj[ny][nx].push_back(make_pair(a, make_pair(i, j)));
				}
			}
		}
		
		pq.push(make_pair(dist[0][0], make_pair(0, 0)));
		while (pq.size())
		{
			int cost = pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();
			
			if (dist[y][x] != cost) continue;
			for (auto there : adj[y][x])
			{
				if (dist[there.second.first][there.second.second] > dist[y][x] + there.first)
				{
					dist[there.second.first][there.second.second] = dist[y][x] + there.first;
					pq.push(make_pair(dist[there.second.first][there.second.second], make_pair(there.second.first, there.second.second)));
				}
			}
		}
		
		cout << "Problem " << cnt++ << ": " << dist[N - 1][N - 1] << '\n';
	}	
}