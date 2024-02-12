#include <iostream>
using namespace std;

int N, r, c;

int func(int n, int r, int c)
{
	if (n == 1) return 0;
	n /= 2;

	// 1사분면
	if (r < n && c < n)
		return func(n, r % n, c % n);
	else if (r < n && c >= n)
		return n * n + func(n, r % n, c % n);
	else if (r >= n && c < n)
		return n * n * 2 + func(n, r % n, c % n);
	else if (r >= n && c >= n)
		return n * n * 3 + func(n, r % n, c % n);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> r >> c;

	N = 1 << N; // 8

	cout << func(N, r, c);
}