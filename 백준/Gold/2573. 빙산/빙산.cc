#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

#define row first
#define col second

short dx[]{ 1, 0, -1, 0 };
short dy[]{ 0, 1, 0, -1 };

int N, M, year;
short iceberg[301][301];
short zero[301][301];
bool visited[301][301];

void CheckIceberg(pair<int, int> startPos)
{
	queue<pair<int, int>> q;
	q.push(startPos);
	visited[startPos.row][startPos.col] = true;
	while (!q.empty())
	{
		pair<int, int> curPos = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nextPos = make_pair(curPos.row + dy[i], curPos.col + dx[i]);
			if (N <= nextPos.row || nextPos.row < 0 || M <= nextPos.col || nextPos.col < 0) continue;
			if (iceberg[nextPos.row][nextPos.col] == 0) continue;
			if (visited[nextPos.row][nextPos.col]) continue;
			q.push(nextPos);
			visited[nextPos.row][nextPos.col] = true;
		}
	}
}

void CheckZeroCount(pair<int, int> icebergPos)
{
	for (int i = 0; i < 4; i++)
	{
		pair<int, int> waterPos = make_pair(icebergPos.row + dy[i], icebergPos.col + dx[i]);
		if (N <= waterPos.row || waterPos.row < 0 || M <= waterPos.col || waterPos.col < 0) continue;
		if (iceberg[waterPos.row][waterPos.col] == 0)
			zero[icebergPos.row][icebergPos.col]++;
	}
}

void MeltingIceberg()
{
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (iceberg[i][j] != 0)
				CheckZeroCount(make_pair(i, j));
		}
	}

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (iceberg[i][j] != 0 && zero[i][j] > 0)
				iceberg[i][j] = iceberg[i][j] - zero[i][j] > 0 ? iceberg[i][j] - zero[i][j] : 0;
		}
	}
}

int main()
{
	// 입력
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> iceberg[i][j];

	while (true)
	{
		// BFS로 빙산이 두 덩어리 이상으로 분리되는지 확인
		int icebergCnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (iceberg[i][j] != 0 && visited[i][j] == false)
				{
					icebergCnt++;
					CheckIceberg(make_pair(i, j));
				}
		if (icebergCnt == 0)
		{
			cout << 0;
			return 0;
		}
		else if (icebergCnt > 1) break;

		// 완전탐색으로 빙산 주변의 바닷물 개수 구해서 빙산 녹이기
		MeltingIceberg();

		year++;
		memset(visited, false, sizeof(visited));
		memset(zero, 0, sizeof(zero));
	}

	cout << year;
}