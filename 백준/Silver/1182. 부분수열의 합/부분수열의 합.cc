#include <iostream>
using namespace std;

int N, S, ans;
int input[20];

void Func(int k, int lastIdx, int sum)
{
	// 공집합이 아니면서 합이 S인 부분 집합을 찾았다!
	if (lastIdx != -1 && sum == S) ans++;
	// base condition
	if (k == N) return;

	for (int i = lastIdx + 1; i < N; i++)
		Func(k + 1, i, sum + input[i]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> input[i];

	Func(0, -1, 0);

	cout << ans;
}