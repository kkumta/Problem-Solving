#include <iostream>
using namespace std;

int A, B, C;

long long func(int b)
{
	if (b == 1) return A % C;

	long long div = func(b / 2);
	// 짝수일 경우
	if (b % 2 == 0)
		return div * div % C;
	// 홀수일 경우
	else
		return (div * div % C) * A % C;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> C;

	cout << func(B);
}