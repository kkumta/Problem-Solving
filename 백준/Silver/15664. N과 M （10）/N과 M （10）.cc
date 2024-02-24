#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int input[9];
int arr[9];

void Func(int k, int lastIdx)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int lastUsedNum = 0;
	for (int i = lastIdx + 1; i < N; i++)
	{
		if (input[i] == lastUsedNum) // 같은 자리에 같은 수가 온다면 continue 
			continue;
		arr[k] = input[i];
		lastUsedNum = input[i];
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

	Func(0, -1);
}