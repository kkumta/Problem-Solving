#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

#define row first
#define col second

short dx[]{ 1, 0, -1, 0 };
short dy[]{ 0, 1, 0, -1 };

int N, M, year;
short curIceberg[301][301];
short nextIceberg[301][301];
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
			if (curIceberg[nextPos.row][nextPos.col] == 0) continue;
			if (visited[nextPos.row][nextPos.col]) continue;
			q.push(nextPos);
			visited[nextPos.row][nextPos.col] = true;
		}
	}
}

void MeltingIceberg(pair<int, int> waterPos)
{
	for (int i = 0; i < 4; i++)
	{
		pair<int, int> icebergPos = make_pair(waterPos.row + dy[i], waterPos.col + dx[i]);
		if (N <= icebergPos.row || icebergPos.row < 0 || M <= icebergPos.col || icebergPos.col < 0) continue;
		if (nextIceberg[icebergPos.row][icebergPos.col] == 0) continue;
		nextIceberg[icebergPos.row][icebergPos.col]--;
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
			cin >> curIceberg[i][j];

	while (true)
	{
		// BFS로 빙산이 두 덩어리 이상으로 분리되는지 확인
		memset(visited, false, sizeof(visited));
		int icebergCnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (curIceberg[i][j] != 0 && visited[i][j] == false)
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

		// 새로운 빙산 배열에 원래 빙산 복사
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				nextIceberg[i][j] = curIceberg[i][j];

		// 완전탐색으로 빙산 녹이기
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (curIceberg[i][j] == 0)
					MeltingIceberg(make_pair(i, j));

		// 원래 빙산 배열에 새로운 빙산 복사
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				curIceberg[i][j] = nextIceberg[i][j];

		year++;
	}

	cout << year;
}