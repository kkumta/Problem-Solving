#include <queue>
#include <iostream>
using namespace std;

int dy[]{ 1, 0, -1, 0 };
int dx[]{ 0, 1, 0, -1 };

int N, M;
char maze[101][101];
int times[101][101];

void BFS()
{
	times[0][0] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		pair<int, int> curPos = q.front();
		if (curPos.first == N - 1 && curPos.second == M - 1) return;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nextPos = make_pair(curPos.first + dy[i], curPos.second + dx[i]);
			if (nextPos.first < 0 || nextPos.first >= N || M <= nextPos.second || nextPos.second < 0) continue;
			if (maze[nextPos.first][nextPos.second] == '0') continue;
			if (times[nextPos.first][nextPos.second] != 0) continue;
			times[nextPos.first][nextPos.second] = times[curPos.first][curPos.second] + 1;
			q.push(nextPos);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
			maze[i][j] = temp[j];
	}

	BFS();

	cout << times[N - 1][M - 1];
}