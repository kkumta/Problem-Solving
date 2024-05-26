#include <bits/stdc++.h>
using namespace std;

int A, B, C;
pair<int, int> t[3];
int ans;

int main()
{
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++)
	{
		cin >> t[i].first;
		cin >> t[i].second;
	}

	for (int i = 1; i < 100; i++)
	{
		int cnt = 0;
		if (t[0].first <= i && t[0].second > i) cnt++;
		if (t[1].first <= i && t[1].second > i) cnt++;
		if (t[2].first <= i && t[2].second > i) cnt++;
		if (cnt == 1) ans += A;
		else if (cnt == 2) ans += 2 * B;
		else if (cnt == 3) ans += 3 * C;
	}
	
	cout << ans;
	
	return 0;
}