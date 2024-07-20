#include <bits/stdc++.h>
using namespace std;

int N, K, alpha, ret;
string w[50];

bool check(int i, int a)
{
	for (int j = 4; j < w[i].size() - 4; j++)
	{
		if (!(a & 1 << ((w[i][j] - 'a'))))
			return false;
	}
	
	return true;
}

void go(int depth, int a, int lastIdx)
{
	if (depth == K)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (check(i, a))
				cnt++;
		}
		
		ret = max(ret, cnt);
		return;
	}
	
	for (int i = lastIdx + 1; i < 26; i++)
	{
		if (a & (1 << i))
			continue;
		go(depth + 1, a | (1 << i), i);
	}
}

int main()
{
	cin >> N >> K;
	if (K < 5)
	{
		cout << 0;
		return 0;
	}
	if (K == 26)
	{
		cout << N;
		return 0;
	}
	
	for (int i = 0; i < N; i++)
		cin >> w[i];
	
	// a, n, t, i, c는 무조건 배워야 한다.
	alpha |= 1 << ('a' - 'a');
	alpha |= 1 << ('n' - 'a');
	alpha |= 1 << ('t' - 'a');
	alpha |= 1 << ('i' - 'a');
	alpha |= 1 << ('c' - 'a');
	
	go(5, alpha, 0);
	
	cout << ret;
}