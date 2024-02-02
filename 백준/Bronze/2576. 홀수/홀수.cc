#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int min = 100;
	for (int i = 0; i < 7; i++)
	{
		int input;
		cin >> input;
		if (input % 2 != 0)
		{
			sum += input;
			if (input < min) min = input;
		}
	}

	if (sum == 0) cout << -1;
	else cout << sum << '\n' << min;
}