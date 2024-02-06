#include <tuple>
#include <queue>
#include <iostream>
using namespace std;

int dx[]{ 0, -1, 0, 1, 0, 0 };
int dy[]{ -1, 0, 1, 0, 0, 0 };
int dz[]{ 0, 0, 0, 0, -1, 1 };

int H, N, M; // 높이, 세로, 가로
int tomatos[101][101][101];
bool visited[101][101][101];
int maxDate = 1;

void bfs(int hPos, int nPos, int mPos)
{
	queue<tuple<int, int, int>> q;

	visited[hPos][nPos][mPos] = true;
	q.push(make_tuple(hPos, nPos, mPos));

	while (!q.empty())
	{
		int curH = get<0>(q.front());
		int curN = get<1>(q.front());
		int curM = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nextH = curH + dz[i];
			int nextN = curN + dy[i];
			int nextM = curM + dx[i];

			if (H <= nextH || nextH < 0 || N <= nextN || nextN < 0 || M <= nextM || nextM < 0) continue;
			if (tomatos[nextH][nextN][nextM] == -1) continue;
			if (tomatos[nextH][nextN][nextM] == 0 || tomatos[nextH][nextN][nextM] > tomatos[curH][curN][curM] + 1)
			{
				tomatos[nextH][nextN][nextM] = tomatos[curH][curN][curM] + 1;
				visited[nextH][nextH][nextH] = true;
				q.push(make_tuple(nextH, nextN, nextM));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++)
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				cin >> tomatos[h][n][m];

	for (int h = 0; h < H; h++)
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				if (tomatos[h][n][m] == 1 && !visited[h][n][m])
					bfs(h, n, m);

	for (int h = 0; h < H; h++)
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
			{
				if (tomatos[h][n][m] == 0)
				{
					cout << -1;
					return 0;
				}
				if (tomatos[h][n][m] > maxDate)
					maxDate = tomatos[h][n][m];
			}

	if (maxDate == 1) cout << 0;
	else cout << maxDate - 1;
}