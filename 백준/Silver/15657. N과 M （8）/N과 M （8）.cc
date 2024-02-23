#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int input[8];
int arr[8];

void Func(int k, int lastIdx)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = lastIdx; i < N; i++)
	{
		arr[k] = input[i];
		Func(k + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> input[i];

	sort(input, input + N);

	Func(0, 0);
}