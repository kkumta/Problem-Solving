#include <bits/stdc++.h>
using namespace std;

int N, L, ret;
int a[100][100], b[100][100];

void solve(int arr[100][100])
{
	for (int i = 0; i < N; i++)
	{
		bool flag = true;
		int cnt = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
				cnt++;
			else if (arr[i][j] + 1 == arr[i][j + 1] && cnt >= L)
				cnt = 1;
			else if (arr[i][j] - 1 == arr[i][j + 1] && cnt >= 0)
				cnt = -L + 1;
			else
			{
				flag = false;
				break;
			}
		}
		
		if (flag && cnt >= 0)
			ret++;
	}
}

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	
	solve(a);
	solve(b);
	
	cout << ret;
}