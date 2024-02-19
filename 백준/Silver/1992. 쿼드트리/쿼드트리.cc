#include <iostream>
using namespace std;

int N;
int picture[65][65];

void func(pair<int, int> startPos, int n)
{
	if (n == 1)
	{
		cout << picture[startPos.first][startPos.second];
		return;
	}

	int cnt0 = 0, cnt1 = 0;
	for (int i = startPos.first; i < startPos.first + n; i++)
		for (int j = startPos.second; j < startPos.second + n; j++)
		{
			if (picture[i][j] == 0)
				cnt0++;
			else
				cnt1++;
		}
	if (cnt0 == 0) // 모든 자리 숫자가 1이면
	{
		cout << '1';
		return;
	}
	else if (cnt1 == 0) // 모든 자리 숫자가 0이면
	{
		cout << '0';
		return;
	}
	else
	{
		n /= 2;
		cout << '(';
		func(startPos, n);
		func(make_pair(startPos.first, startPos.second + n), n);
		func(make_pair(startPos.first + n, startPos.second), n);
		func(make_pair(startPos.first + n, startPos.second + n), n);
		cout << ')';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)
			picture[i][j] = temp[j] - '0';
	}

	func(make_pair(0, 0), N);
}