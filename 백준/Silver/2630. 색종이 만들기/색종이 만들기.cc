#include <iostream>
using namespace std;

int N;
int paper[129][129];
int ans[2];

void func(pair<int, int> startPos, int n)
{
	// 종료 조건 확인
	int whiteCnt = 0, blueCnt = 0;
	for (int i = startPos.first; i < startPos.first + n; i++)
		for (int j = startPos.second; j < startPos.second + n; j++)
		{
			if (paper[i][j] == 0) whiteCnt++;
			else blueCnt++;
		}

	if (whiteCnt == 0)
	{
		ans[1]++;
		return;
	}
	else if (blueCnt == 0)
	{
		ans[0]++;
		return;
	}

	// 이어서 분할하기
	n /= 2;
	func(make_pair(startPos.first, startPos.second), n);
	func(make_pair(startPos.first, startPos.second + n), n);
	func(make_pair(startPos.first + n, startPos.second), n);
	func(make_pair(startPos.first + n, startPos.second + n), n);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	func(make_pair(0, 0), N);

	cout << ans[0] << '\n' << ans[1];
}