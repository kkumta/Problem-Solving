#include <bits/stdc++.h>
using namespace std;

class Shark
{
public:
	int r, c, s, d, z;
	bool isDead;
};

int R, C, M, ret;
Shark a[10001];
int maps[101][101], newMaps[101][101];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

int main()
{
	cin >> R >> C >> M;

	for (int i = 1; i <= M; i++)
	{
		cin >> a[i].r >> a[i].c >> a[i].s >> a[i].d >> a[i].z;
		a[i].r--; a[i].c--; a[i].d--;
		maps[a[i].r][a[i].c] = i;
	}
	
	for (int person = 0; person < C; person++)
	{			
		// 낚시하기 
		for (int row = 0; row < R; row++)
		{
			if (maps[row][person])
			{
				ret += a[maps[row][person]].z;
				a[maps[row][person]].isDead = true;
				break;
			}
		}

		memset(newMaps, 0, sizeof(newMaps));
		
		// 상어 이동하기
		for (int i = 1; i <= M; i++)
		{
			if (a[i].isDead) continue;
			
			int ny, nx, y = a[i].r, x = a[i].c, s = a[i].s, d = a[i].d, z = a[i].z;
			while (true)
			{
				ny = y + dy[d] * s;
				nx = x + dx[d] * s;
				
				if (ny >= 0 && ny < R && nx >= 0 && nx < C)	break;
				
				// 양끝으로 가는 거리만큼 속력 빼주기
				if (d <= 1) // 상하 이동
				{
					if (ny < 0)
					{
						s -= y;
						y = 0;
					}
					else
					{
						s -= R - y - 1;
						y = R - 1;
					}
				}
				else // 좌우 이동 
				{
					if (nx < 0)
					{
						s -= x;
						x = 0;
					}
					else
					{
						s -= C - x - 1;
						x = C - 1;
					}	
				} 
				
				// 방향 전환 
				d ^= 1;
			}
			
			a[i].r = ny;
			a[i].c = nx;
			a[i].d = d;
			
			// 상어끼리 잡아먹기
			if (a[newMaps[ny][nx]].z < a[i].z)
			{
				a[newMaps[ny][nx]].isDead = true;
				newMaps[ny][nx] = i;
			}
			else
				a[i].isDead = true;
		}
		
		// newMaps -> maps
		memcpy(maps, newMaps, sizeof(maps));
	}
	
	cout << ret;
}