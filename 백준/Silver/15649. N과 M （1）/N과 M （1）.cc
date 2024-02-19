#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool isUsed[9];

void func(int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	for (int i = 1; i <= N; i++)
	{
		if (isUsed[i]) continue;
		isUsed[i] = true;
		arr[k] = i;
		func(k + 1);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	func(0);
}