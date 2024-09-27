#include <bits/stdc++.h>
using namespace std;

const int mod = 1000007;
int N, M, C, r, c;
int maps[51][51]; // 오락실 번호 
int d[51][51][51][51]; // 해당 장소로 가는 경로의 수: y, x, 앞으로 들를 오락실 수, 마지막으로 들른 오락실 번호 

int go(int y, int x, int cnt, int lastIdx)
{
	if (y > N || x > M) return 0;
	if (y == N && x == M)
	{
		if ((cnt == 0 && maps[y][x] == 0) || (cnt == 1 && maps[y][x] > lastIdx)) return 1;
		else return 0; 
	}
	
	if (d[y][x][cnt][lastIdx] != -1) return d[y][x][cnt][lastIdx];
	
	int ret = 0;	
	if (maps[y][x] == 0) ret = (go(y + 1, x, cnt, lastIdx) + go(y, x + 1, cnt, lastIdx)) % mod;
	else if (maps[y][x] > lastIdx) ret = (go(y + 1, x, cnt - 1, maps[y][x]) + go(y, x + 1, cnt - 1, maps[y][x])) % mod;
	
	return d[y][x][cnt][lastIdx] = ret;
}

int main()
{
	cin >> N >> M >> C;
	for (int i = 1; i <= C; i++)
	{
		cin >> r >> c;
		maps[r][c] = i;
	}
	
	fill(&d[0][0][0][0], &d[0][0][0][0] + 51 * 51 * 51 * 51, -1);
	for (int i = 0; i <= C; i++) cout << go(1, 1, i, 0) << ' ';
}