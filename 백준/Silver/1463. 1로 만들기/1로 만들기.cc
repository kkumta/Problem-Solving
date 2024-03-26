#include <iostream>
using namespace std;

int n;
int d[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	d[2] = 1; d[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		int min = d[i - 1];
		if (i % 2 == 0 && d[i / 2] < min)
			min = d[i / 2];
		if (i % 3 == 0 && d[i / 3] < min)
			min = d[i / 3];
		d[i] = ++min;
	}

	cout << d[n];
}