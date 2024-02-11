#include <tuple>
#include <queue>
#include <iostream>
using namespace std;

int dy[]{ 1, 0, -1, 0 };
int dx[]{ 0, 1, 0, -1 };

int N, M;
char map[1001][1001];
int dist[2][1001][1001];

void BFS()
{
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 1;
	while (!q.empty())
	{
		tuple<int, int, int> curPos = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int curBreakCount = get<0>(curPos);
			int nextRow = get<1>(curPos) + dy[i];
			int nextCol = get<2>(curPos) + dx[i];

			if (N <= nextRow || nextRow < 0 || M <= nextCol || nextCol < 0) continue;
			if (curBreakCount == 0)
			{
				// 부수지 않고 이동
				if (map[nextRow][nextCol] == '0' && dist[curBreakCount][nextRow][nextCol] == 0)
				{
					q.push(make_tuple(curBreakCount, nextRow, nextCol));
					dist[curBreakCount][nextRow][nextCol] = dist[curBreakCount][get<1>(curPos)][get<2>(curPos)] + 1;
				}
				// 부수고 이동
				if (map[nextRow][nextCol] == '1' && dist[curBreakCount + 1][nextRow][nextCol] == 0)
				{
					q.push(make_tuple(curBreakCount + 1, nextRow, nextCol));
					dist[curBreakCount + 1][nextRow][nextCol] = dist[curBreakCount][get<1>(curPos)][get<2>(curPos)] + 1;
				}
			}
			else
			{
				// 부수지 않고 이동
				if (map[nextRow][nextCol] == '0' && dist[curBreakCount][nextRow][nextCol] == 0)
				{
					q.push(make_tuple(curBreakCount, nextRow, nextCol));
					dist[curBreakCount][nextRow][nextCol] = dist[curBreakCount][get<1>(curPos)][get<2>(curPos)] + 1;
				}
			}
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
			map[i][j] = temp[j];
	}

	BFS();

	if (dist[0][N - 1][M - 1] == 0 && dist[1][N - 1][M - 1] == 0) cout << -1;
	else if (dist[0][N - 1][M - 1] == 0) cout << dist[1][N - 1][M - 1];
	else if (dist[1][N - 1][M - 1] == 0) cout << dist[0][N - 1][M - 1];
	else cout << min(dist[0][N - 1][M - 1], dist[1][N - 1][M - 1]);
}