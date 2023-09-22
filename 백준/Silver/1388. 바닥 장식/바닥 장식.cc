#include <iostream>
using namespace std;

#define MAX_SIZE 50
int floorShapes[MAX_SIZE][MAX_SIZE];
bool isVisited[MAX_SIZE][MAX_SIZE];

void search(int row, int col)
{
	if (floorShapes[row][col] == 1)
	{
		for (int i = col; i < MAX_SIZE; i++)
		{
			if (floorShapes[row][i] != 1)
				break;

			isVisited[row][i] = true;
		}
	}
	else
	{
		for (int i = row; i < MAX_SIZE; i++)
		{
			if (floorShapes[i][col] != 2)
				break;

			isVisited[i][col] = true;
		}
	}
}

int main()
{
	int ans = 0;
	int n, m;
	cin >> n;
	cin >> m;

	// 바닥 채워 넣기
	for (int row = 0; row < n; row++)
	{
		string shape;
		cin >> shape;
		for (int col = 0; col < m; col++)
		{
			if (shape[col] == '-')
				floorShapes[row][col] = 1;
			else
				floorShapes[row][col] = 2;
		}
	}

	// 바닥에 필요한 타일 개수 세기
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			if (!isVisited[row][col])
			{
				search(row, col);
				ans++;
			}
		}
	}

	cout << ans << endl;
}