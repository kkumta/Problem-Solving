#include <iostream>
using namespace std;

int n;
int house[1000][3], d[1000][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> house[i][j];

	d[0][0] = house[0][0];
	d[0][1] = house[0][1];
	d[0][2] = house[0][2];

	for (int i = 1; i < n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + house[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + house[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + house[i][2];
	}

	cout << min(d[n - 1][0], min(d[n - 1][1], d[n - 1][2]));
}