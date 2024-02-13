#include <iostream>
using namespace std;

int N;

void func(int fromPillar, int toPillar, int n)
{
	if (n == 1)
	{
		cout << fromPillar << ' ' << toPillar << '\n';
		return;
	}
	func(fromPillar, 6 - fromPillar - toPillar, n - 1);
	cout << fromPillar << ' ' << toPillar << '\n';
	func(6 - fromPillar - toPillar, toPillar, n - 1);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	cout << (1 << N) - 1 << '\n';
	func(1, 3, N);
}