#include <bits/stdc++.h>
using namespace std;

int T, M, N, K, ret;
int maps[50][50];
bool visited[50][50];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

void bfs(int y, int x)
{
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		pair<int, int> curPos = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = curPos.first + dy[i];
			int nextX = curPos.second + dx[i];
			
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
			if (maps[nextY][nextX] == 0 || visited[nextY][nextX]) continue;
			
			visited[nextY][nextX] = true;
			q.push(make_pair(nextY, nextX));
		}
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		fill(&maps[0][0], &maps[0][0] + 2500, 0);
		fill(&visited[0][0], &visited[0][0] + 2500, false);
		ret = 0;
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> x >> y;
			maps[y][x] = 1;
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (maps[j][k] == 1 && !visited[j][k])
				{
					bfs(j, k);
					ret++;
				}
			}
		}
		
		cout << ret << '\n';
	}
}