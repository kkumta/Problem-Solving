#include <bits/stdc++.h>
using namespace std;

int N, M, K, ret;
int r, c, m, d, s;
vector<vector<int>> v;
vector<vector<int>> maps[51][51];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void moveFireball()
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		int ny = v[i][0] + dy[v[i][4]] * v[i][3];
		int nx = v[i][1] + dx[v[i][4]] * v[i][3];
		
		while (ny < 0) ny += N;
		while (nx < 0) nx += N;
		
		ny %= N;
		nx %= N;
		
		v[i][0] = ny;
		v[i][1] = nx;
	}
}

void reflectToMaps()
{
	for (int i = v.size() - 1; v.size() != 0; i--)
	{	
		maps[v[i][0]][v[i][1]].push_back(v[i]);
		v.pop_back();
	}
}

void combineFireballs()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maps[i][j].size() > 1)
			{
				vector<vector<int>> tmp;
				int sm = 0, ss = 0, evenCount = 0;
				for (vector<int> c : maps[i][j])
				{
					sm += c[2];
					ss += c[3];
					if (c[4] % 2 == 0)
						evenCount++;
				}
				
				sm /= 5;
				if (sm == 0)
				{
					maps[i][j].clear();
					continue;
				}
				
				ss /= maps[i][j].size();
				if (evenCount == maps[i][j].size() || evenCount == 0)
				{
					for (int b : {0, 2, 4, 6})
					{
						vector<int> a;
						a.push_back(i); a.push_back(j); a.push_back(sm); a.push_back(ss); a.push_back(b);
						tmp.push_back(a);
					}
				}
				else
				{
					for (int b : {1, 3, 5, 7})
					{
						vector<int> a;
						a.push_back(i); a.push_back(j); a.push_back(sm); a.push_back(ss); a.push_back(b);
						tmp.push_back(a);
					}					
				}
				
				maps[i][j].clear();
				for (int k = 0; k < tmp.size(); k++)
					maps[i][j].push_back(tmp[k]);
			}
		}
	}
}

void mapsToV()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = maps[i][j].size() - 1; k >= 0; k--)
			{
				v.push_back(maps[i][j][k]);
				maps[i][j].pop_back();
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> m >> s >> d;
		vector<int> tmp;
		tmp.push_back(r - 1);
		tmp.push_back(c - 1);
		tmp.push_back(m);
		tmp.push_back(s);
		tmp.push_back(d);
		v.push_back(tmp);
	}
	
	for (int i = 0; i < K; i++)
	{
		// 1. d로 s만큼 이동시키기
		moveFireball();
		
		// 2. 이동시킨 파이어볼을 maps에 반영하기
		reflectToMaps();
		
		// 3. maps의 파이어볼 합치기
		combineFireballs();
		
		// 4. 다시 v에 maps에 있는 모든 파이어볼의 정보 넣기
		mapsToV();
	}
	
	// 남아있는 파이어볼 질량의 합 구하기
	for (vector<int> a : v)
		ret += a[2];
	
	cout << ret;
}