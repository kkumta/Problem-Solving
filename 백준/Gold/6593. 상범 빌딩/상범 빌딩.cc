#include <tuple>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int dx[]{ 0, -1, 0, 1, 0, 0 };
int dy[]{ -1, 0, 1, 0, 0, 0 };
int dz[]{ 0, 0, 0, 0, -1, 1 };

int L, R, C; // 높이, 세로, 가로
char building[31][31][31];
int times[31][31][31];
tuple<int, int, int> S;
tuple<int, int, int> E;

void bfs(tuple<int, int, int> S)
{
	queue<tuple<int, int, int>> q;
	q.push(S);
	times[get<0>(S)][get<1>(S)][get<2>(S)] = 1;
	while (!q.empty())
	{
		tuple<int, int, int> curPos = q.front();
		if (curPos == E) return;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			tuple<int, int, int> nextPos = make_tuple(get<0>(curPos) + dz[i], get<1>(curPos) + dy[i], get<2>(curPos) + dx[i]);
			if (L <= get<0>(nextPos) || get<0>(nextPos) < 0 || R <= get<1>(nextPos) || get<1>(nextPos) < 0 || C <= get<2>(nextPos) || get<2>(nextPos) < 0) continue;
			if (building[get<0>(nextPos)][get<1>(nextPos)][get<2>(nextPos)] == '#') continue;
			if (times[get<0>(nextPos)][get<1>(nextPos)][get<2>(nextPos)] != 0) continue;

			times[get<0>(nextPos)][get<1>(nextPos)][get<2>(nextPos)] = times[get<0>(curPos)][get<1>(curPos)][get<2>(curPos)] + 1;
			q.push(nextPos);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0) break;

		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				string row;
				cin >> row;
				for (int k = 0; k < C; k++)
				{
					building[i][j][k] = row[k];
					if (building[i][j][k] == 'S') S = make_tuple(i, j, k);
					else if (building[i][j][k] == 'E') E = make_tuple(i, j, k);
				}
			}

		}

		memset(times, 0, sizeof(times));
		bfs(S);

		if (times[get<0>(E)][get<1>(E)][get<2>(E)] == 0) cout << "Trapped!" << endl;
		else cout << "Escaped in " << times[get<0>(E)][get<1>(E)][get<2>(E)] - 1 << " minute(s)." << endl;
	}
}