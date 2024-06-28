#include <bits/stdc++.h>
using namespace std;

int N, ret = 100000000;
int scvs[3];

void attack(int a, int b, int c, int cnt)
{	
	if (a == 0 && b == 0 && c == 0)
	{
		ret = min(cnt, ret);
		return;
	}
	
	if (cnt >= ret)
	{
		return;
	}

	if (a >= b && a >= c)
	{
		attack(max(a - 9, 0), max(b - 3, 0), max(c - 1, 0), cnt + 1);
		attack(max(a - 9, 0), max(b - 1, 0), max(c - 3, 0), cnt + 1);
	}
	else if (b >= a && b >= c)
	{
		attack(max(a - 3, 0), max(b - 9, 0), max(c - 1, 0), cnt + 1);
		attack(max(a - 1, 0), max(b - 9, 0), max(c - 3, 0), cnt + 1);
	}
	else if (c >= a && c >= b)
	{
		attack(max(a - 1, 0), max(b - 3, 0), max(c - 9, 0), cnt + 1);
		attack(max(a - 3, 0), max(b - 1, 0), max(c - 9, 0), cnt + 1);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> scvs[i];
	
	// 각 경우마다 공격 횟수 구하기 
	attack(scvs[0], scvs[1], scvs[2], 0);
	
	cout << ret;
}