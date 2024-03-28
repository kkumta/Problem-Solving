#include <iostream>
using namespace std;

int n, m;
int numbers[100001], d[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> numbers[i];

	for (int i = 1; i <= n; i++)
		d[i] = d[i - 1] + numbers[i];

	for (int k = 0; k < m; k++)
	{
		int i, j;
		cin >> i >> j;
		cout << d[j] - d[i - 1] << '\n';
	}
}