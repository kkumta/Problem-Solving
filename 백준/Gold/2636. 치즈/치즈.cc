#include <bits/stdc++.h>
using namespace std;

int N, M;
int maps[100][100];
bool visited[100][100];
int ret1, ret2;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

bool IsAllCheeseMelted()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maps[i][j] == 1)
				cnt++;
		}
	}
	
	// 전부 다 녹았으면 이미 저장된 ret1, ret2 사용
	if (cnt == 0)
		return true;
	
	// 전부 다 녹지 않았으면 ret1, ret2의 값 변경
	ret1++;
	ret2 = cnt;
	return false; 
}

void Dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		
		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
		if (maps[nextY][nextX] == 1) maps[nextY][nextX] = 2;
		else if (maps[nextY][nextX] == 0 && !visited[nextY][nextX])
		{
			visited[nextY][nextX] = true;
			Dfs(nextY, nextX);
		}
	}
}

void FindMeltingArea()
{
	fill(&visited[0][0], &visited[0][0] + 100 * 100, false);
	
	for (int i = 0; i < N; i++)
	{
		if (!visited[i][0])
			Dfs(i, 0);
		if (!visited[i][M - 1])
			Dfs(i, M - 1);		
	}
	
	for (int i = 0; i < M; i++)
	{
		if (!visited[0][i])
			Dfs(0, i);
		if (!visited[N - 1][i])
			Dfs(N - 1, i);		
	}
}

void Melt()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maps[i][j] == 2)
				maps[i][j] = 0;
		}
	}	
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
		}
	}
	
	while(!IsAllCheeseMelted())
	{
		// 녹일 부분 구하기
		FindMeltingArea();
		
		// 녹이기
		Melt();
	}
	
	cout << ret1 << '\n' << ret2;
}