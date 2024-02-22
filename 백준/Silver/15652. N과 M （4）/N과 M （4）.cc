#include <iostream>
using namespace std;

int N, M;
int arr[8];
void Func(int k, int lastNum)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = lastNum; i <= N; i++)
	{
		arr[k] = i;
		Func(k + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	Func(0, 1);
}