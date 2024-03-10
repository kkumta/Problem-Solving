#include <iostream>
using namespace std;

int t, n;
int arr[101];

int gcd(int m, int n)
{
	if (m < n)
		swap(m, n);

	while (n != 0)
	{
		int r = m % n;
		m = n;
		n = r;
	}

	return m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long sum = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> arr[j];

		for (int j = 0; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum += gcd(arr[j], arr[k]);
			}
		}
		cout << sum << '\n';
	}
}