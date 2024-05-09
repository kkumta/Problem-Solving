#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int A[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		if (binary_search(A, A + N, num))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}