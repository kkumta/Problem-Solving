#include <bits/stdc++.h>
using namespace std;

int R, C, T, firstRow = -1, secondRow = -1, ret;
int maps[50][50], newMaps[50][50];
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

// 미세먼지 확산 
void func1()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (maps[i][j] == -1)
			{
				newMaps[i][j] = -1;
				continue;
			}
			int tmp = maps[i][j] / 5;			
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny >= 0 && ny < R && nx >= 0 && nx < C && maps[ny][nx] != -1)
				{
					newMaps[ny][nx] += tmp;
					cnt++;
				}
			}
			
			newMaps[i][j] += maps[i][j] - tmp * cnt;
		}
		
	// newMaps -> maps
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			maps[i][j] = newMaps[i][j];
			
	// newMaps 초기화
	fill(&newMaps[0][0], &newMaps[R - 1][C], 0);
}

// 공기청정기 작동
void func2()
{
	// 위쪽은 반시계방향 순환
	// 바람 방향: 오른쪽
	newMaps[firstRow][1] = 0;
	for (int i = 1; i < C - 1; i++)
		newMaps[firstRow][i + 1] = maps[firstRow][i];
	// 바람 방향: 위쪽
	for (int i = firstRow; i > 0; i--)
	 	newMaps[i - 1][C - 1] = maps[i][C - 1];
	// 바람 방향: 왼쪽
	for (int i = C - 1; i > 0; i--)
		newMaps[0][i - 1] = maps[0][i];
	// 바람 방향: 아래쪽
	for (int i = 0; i < firstRow - 1; i++)
		newMaps[i + 1][0] = maps[i][0];
	
	// 아래쪽은 시계방향 순환
	// 바람 방향: 오른쪽
	newMaps[secondRow][1] = 0;
	for (int i = 1; i < C - 1; i++)
		newMaps[secondRow][i + 1] = maps[secondRow][i];
	// 바람 방향: 아래쪽
	for (int i = secondRow; i < R - 1; i++)
		newMaps[i + 1][C - 1] = maps[i][C - 1];
	// 바람 방향: 왼쪽
	for (int i = C - 1; i > 0; i--)
		newMaps[R - 1][i - 1] = maps[R - 1][i];
	// 바람 방향: 위쪽
	for (int i = R - 1; i > secondRow + 1; i--)
	 	newMaps[i - 1][0] = maps[i][0];
		 		
	// 공기청정기 영향이 없는 부분
	for (int i = 1; i < firstRow; i++)
		for (int j = 1; j < C - 1; j++)
			newMaps[i][j] = maps[i][j];		 		
	for (int i = secondRow + 1; i < R - 1; i++)
		for (int j = 1; j < C - 1; j++)
			newMaps[i][j] = maps[i][j];
			
	// newMaps -> maps
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			maps[i][j] = newMaps[i][j];
	
	// newMaps 초기화
	fill(&newMaps[0][0], &newMaps[R - 1][C], 0);
} 

// 미세먼지의 양 측정 
void func3()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (maps[i][j] > 0)
				ret += maps[i][j];
}

int main()
{
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == -1)
			{
				if (firstRow == -1)
					firstRow = i;
				else
					secondRow = i;
			}
		}
	}
	
	for (int t = 0; t < T; t++)
	{
		// 미세먼지 확산
		func1();
		// 공기청정기 작동
		func2(); 
	}
	
	func3();
	
	cout << ret;
}