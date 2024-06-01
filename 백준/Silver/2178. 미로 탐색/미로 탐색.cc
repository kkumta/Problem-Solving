#include <bits/stdc++.h>
using namespace std;

int N, M;
int maps[100][100];
int cnt[100][100];
queue<pair<int, int>> q;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void bfs(int y, int x)
{
	cnt[y][x] = 1;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		pair<int, int> curPos = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = curPos.first + dy[i];
			int nextX = curPos.second + dx[i];
			
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
			if (maps[nextY][nextX] == 0) continue;
			if (cnt[nextY][nextX] != 0) continue;
			cnt[nextY][nextX] = cnt[curPos.first][curPos.second] + 1;
			q.push(make_pair(nextY, nextX));
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
			maps[i][j] = tmp[j] - '0';
	}

	bfs(0, 0);
	
	cout << cnt[N - 1][M - 1];
}