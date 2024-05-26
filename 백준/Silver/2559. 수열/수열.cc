#include <bits/stdc++.h>
using namespace std;

int N, K, ans = -100 * 100000;
int a[100001], p[100001];

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	
	for (int i = 1; i <= N; i++)
		p[i] += p[i - 1] + a[i];
	
	for (int i = K; i <= N; i++)
	{
		int tmp = p[i] - p[i - K];
		if (tmp > ans)
			ans = tmp;
	}
	
	cout << ans;
	
	return 0;
}