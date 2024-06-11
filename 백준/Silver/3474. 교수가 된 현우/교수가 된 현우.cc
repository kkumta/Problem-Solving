#include <bits/stdc++.h>
using namespace std;

int N, n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		
		int d2 = 0, d5 = 0;
		for (int j = 2; j <= n; j *= 2)
		{
			d2 += n / j;
		}
		for (int j = 5; j <= n; j *= 5)
		{
			d5 += n / j;
		}
		
		cout << min(d2, d5) << '\n';
	}
	
	return 0;
}