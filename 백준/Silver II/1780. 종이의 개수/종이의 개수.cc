#include <iostream>
using namespace std;

int N;
int paper[2188][2188];
int ans[3];

void func(pair<int, int> start, pair<int, int> end, int n)
{
	// 종료 조건 확인
	int count[] = { 0, 0, 0 };
	for (int i = start.first; i <= end.first; i++)
		for (int j = start.second; j <= end.second; j++)
		{
			if (paper[i][j] == -1) count[0]++;
			else if (paper[i][j] == 0) count[1]++;
			else count[2]++;
		}
	if (count[1] == 0 && count[2] == 0)
	{
		ans[0]++;
		return;
	}
	else if (count[0] == 0 && count[2] == 0)
	{
		ans[1]++;
		return;
	}
	else if (count[0] == 0 && count[1] == 0)
	{
		ans[2]++;
		return;
	}

	// 9군데로 나눠서 다시 탐색
	n /= 3;
	func(make_pair(start.first, start.second), make_pair(end.first - n * 2, end.second - n * 2), n);
	func(make_pair(start.first, start.second + n), make_pair(end.first - n * 2, end.second - n), n);
	func(make_pair(start.first, start.second + n * 2), make_pair(end.first - n * 2, end.second), n);
	func(make_pair(start.first + n, start.second), make_pair(end.first - n, end.second - n * 2), n);
	func(make_pair(start.first + n, start.second + n), make_pair(end.first - n, end.second - n), n);
	func(make_pair(start.first + n, start.second + n * 2), make_pair(end.first - n, end.second), n);
	func(make_pair(start.first + n * 2, start.second), make_pair(end.first, end.second - n * 2), n);
	func(make_pair(start.first + n * 2, start.second + n), make_pair(end.first, end.second - n), n);
	func(make_pair(start.first + n * 2, start.second + n * 2), make_pair(end.first, end.second), n);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	func(make_pair(0, 0), make_pair(N - 1, N - 1), N);
	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];
}