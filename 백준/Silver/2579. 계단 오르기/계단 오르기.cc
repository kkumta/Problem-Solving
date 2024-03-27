#include <iostream>
using namespace std;

int n;
int stairs[301], d[301];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> stairs[i];

	d[1] = stairs[1];
	d[2] = stairs[1] + stairs[2];

	for (int i = 3; i <= n; i++)
		d[i] = max(d[i - 2] + stairs[i], d[i - 3] + stairs[i - 1] + stairs[i]);

	cout << d[n];
}