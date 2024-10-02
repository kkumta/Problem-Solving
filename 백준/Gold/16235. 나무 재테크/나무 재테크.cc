#include <bits/stdc++.h>
using namespace std;

int N, M, K, ret;
int a[11][11]; // 매년 추가되는 양분 
int b[11][11]; // 현재 양분
vector<int> c[11][11]; // 나무 목록
int dy[] = {0, 0, 1, 1, 1, -1, -1, -1}, dx[] = {1, -1, 1, -1, 0, 1, -1, 0};

void springSummer()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{	
			vector<int> nextTrees;
			int deadTrees = 0;	
			sort(c[i][j].begin(), c[i][j].end());
			for (int k = 0; k < c[i][j].size(); k++)
			{
				int tree = c[i][j][k];
				if (b[i][j] >= tree)
				{
					b[i][j] -= tree;
					nextTrees.push_back(tree + 1);
				}
				else
					deadTrees += tree / 2;											
			}
			c[i][j] = nextTrees;
			b[i][j] += deadTrees;
		}
	}
}

void autumn()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int tree : c[i][j])
			{
				if (tree % 5 == 0)
				{
					for (int k = 0; k < 8; k++)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) c[ny][nx].push_back(1);
					}					
				}
			}
		}
	}
}

void winter()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			b[i][j] += a[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> a[i][j];
			
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		c[x][y].push_back(z);
	}
	
	fill(&b[0][0], &b[0][0] + 11 * 11, 5);
	
	for (int i = 0; i < K; i++)
	{
		springSummer();
		autumn();
		winter();
	}
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ret += c[i][j].size();

	cout << ret;
}