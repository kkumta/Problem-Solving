#include <bits/stdc++.h>
using namespace std;

int N, ret = 200 * 100;
vector<pair<int, int>> v;
bool visited[10][10];
int g[10][10];
int dy[] = {0, 0, 1, 0, -1};
int dx[] = {0, 1, 0, -1, 0};

void go(int depth, int sum)
{
	if (depth == 3)
	{
		ret = min(sum, ret);
		return;
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		bool flag = false;
		int s = 0;
		for (int j = 0; j < 5; j++)
		{
			int ny = v[i].first + dy[j];
			int nx = v[i].second + dx[j];
			if (visited[ny][nx])
			{
				flag = true;
				break;
			}
			s += g[ny][nx];
		}		
		if (flag) continue;
		
		for (int j = 0; j < 5; j++)
		{
			int ny = v[i].first + dy[j];
			int nx = v[i].second + dx[j];
			visited[ny][nx] = true;	
		}
		
		go(depth + 1, sum + s);
		
		for (int j = 0; j < 5; j++)
		{
			int ny = v[i].first + dy[j];
			int nx = v[i].second + dx[j];
			visited[ny][nx] = false;	
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> g[i][j];
			if (i != 0 && i != N - 1 && j != 0 && j != N - 1)
				v.push_back(make_pair(i, j));
		}
	}
	
	go(0, 0);
	
	cout << ret;
}