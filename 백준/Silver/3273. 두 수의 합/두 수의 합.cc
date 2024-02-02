#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	int n, x;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> x;

	// 정렬
	sort(v.begin(), v.end());

	// 합이 x가 되는 쌍 구하기
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] + v[j] >= x)
			{
				if (v[i] + v[j] == x) ans++;
				break;
			}
		}
	}

	cout << ans;
}