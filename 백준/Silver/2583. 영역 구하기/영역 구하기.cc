#include <bits/stdc++.h>
using namespace std;

int M, N, K;
bool maps[100][100];
bool visited[100][100];
int cnt;
int ret1;
vector<int> ret2;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int y, int x)
{
	visited[y][x] = true;
	cnt++;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
		if (maps[ny][nx]) continue;
		if (visited[ny][nx]) continue;
		
		dfs(ny, nx);
	}
}

int main()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int j = y1; j < y2; j++)
			for (int k = x1; k < x2; k++)
				maps[j][k] = true;
	}
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (maps[i][j]) continue;
			if (visited[i][j]) continue;
			
			cnt = 0;
			dfs(i, j);
			ret1++;
			ret2.push_back(cnt);
		}
	
	sort(ret2.begin(), ret2.end());
	
	cout << ret1 << '\n';
	for (int r : ret2)
		cout << r << ' ';
		
	return 0;
}