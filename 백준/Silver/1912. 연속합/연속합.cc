#include <iostream>
using namespace std;

int n, ans= -100000000;
int arr[100000], d[91];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	d[0] = arr[0];
	for (int i = 1; i < n; i++)
		d[i] = max(d[i - 1], 0) + arr[i];

	for (int i = 0; i < n; i++)
		if (d[i] > ans) ans = d[i];

	cout << ans;
}