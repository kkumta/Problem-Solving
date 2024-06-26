#include <bits/stdc++.h>
using namespace std;

int N, L, R, ret;
int maps[50][50];
bool visited[50][50];
vector<pair<int, int>> countries;
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int dfs(int y, int x)
{
	visited[y][x] = true;
	countries.push_back(make_pair(y, x));
	int sum = maps[y][x];
	
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		
		if (nextY >= N || nextY < 0 || nextX >= N || nextX < 0) continue;
		if (visited[nextY][nextX]) continue;
		if (abs(maps[y][x] - maps[nextY][nextX]) >= L && abs(maps[y][x] - maps[nextY][nextX]) <= R)
			sum += dfs(nextY, nextX);
	}
	
	return sum;
}

int main()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> maps[i][j];

	while (true)
	{
		fill(&visited[0][0], &visited[0][0] + 50 * 50, false);
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					countries.clear();
					visited[i][j] = true;
					int sum = dfs(i, j);
					if (countries.size() >= 2)
						flag = true;
					int p = sum / countries.size();
					for (pair<int, int> country : countries)
						maps[country.first][country.second] = p;
				}
			}
		}
		
		if (flag)
			ret++;
		else break;
	}
	
	cout << ret;
}