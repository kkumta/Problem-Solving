#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define row first
#define col second

int drow[]{ 1, 0, -1, 0 };
int dcol[]{ 0, 1, 0, -1 };

int n, m, ans;
vector<int> pictureSizes;
int paper[501][501];
bool isSearched[501][501];

int bfs(pair<int, int> pos)
{
	int pictureSize = 0;
	queue<pair<int, int>> q;

	q.push(pos);
	isSearched[pos.row][pos.col] = true;

	while (!q.empty())
	{
		pair<int, int> curPos = q.front(); q.pop();
		pictureSize++;
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nextPos = make_pair<int, int>(curPos.row + drow[i], curPos.col + dcol[i]);

			if (n <= nextPos.row || nextPos.row < 0 || m <= nextPos.col || nextPos.col < 0) continue;
			if (!paper[nextPos.row][nextPos.col]) continue;
			if (isSearched[nextPos.row][nextPos.col]) continue;

			q.push(make_pair(nextPos.row, nextPos.col));
			isSearched[nextPos.row][nextPos.col] = true;
		}
	}

	return pictureSize;
}

int main()
{
	// 입력
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}

	// BFS로 아직 탐색되지 않은 곳의 그림 탐색
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (paper[i][j] && !isSearched[i][j])
				pictureSizes.push_back(bfs(make_pair(i, j)));
	}

	for (int s : pictureSizes)
		if (s > ans) ans = s;

	cout << pictureSizes.size() << '\n' << ans;
}