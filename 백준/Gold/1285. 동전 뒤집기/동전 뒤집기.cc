#include <bits/stdc++.h>
using namespace std;

int N, ret = 400;
int a[20];

void go(int idx)
{
	if (idx == N)
	{
		// 각 열 기준으로 T 개수 구하기 
		int sum = 0;
		for (int i = 1; i < (1 << N); i *= 2)
		{
			int cnt = 0;
			for (int j = 0; j < N; j++)
				if (a[j] & i)
					cnt++;
			sum += min(cnt, N - cnt);
		}
		ret = min(ret, sum);
		
		return;
	}
	
	go(idx + 1);
	a[idx] = ~a[idx];
	go(idx + 1);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		int value = 1;
		for (int j = 0; j < N; j++)
		{
			if (tmp[j] == 'T')
				a[i] += value;
			value *= 2;
		}
	}
	
	go(0);
	
	cout << ret;
}