#include <bits/stdc++.h>
using namespace std;

int T, N, M, target;
int a[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int n = 0; n < N; n++)
			cin >> a[n];
		sort(a, a + N);
		
		cin >> M;
		for (int m = 0; m < M; m++)
		{
			cin >> target;
			if (binary_search(a, a + N, target))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}