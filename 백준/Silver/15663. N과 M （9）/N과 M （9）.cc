#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int input[9];
int arr[9];
bool isUsed[9];

void Func(int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int lastUsedNum = 0;
	for (int i = 0; i < N; i++)
	{
		if (isUsed[i] || input[i] == lastUsedNum) // 이미 사용된 input이거나, 같은 자리에 같은 수가 온다면 continue 
			continue;
		isUsed[i] = true;
		arr[k] = input[i];
		lastUsedNum = input[i];
		Func(k + 1);
		isUsed[i] = false;
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

	Func(0);
}