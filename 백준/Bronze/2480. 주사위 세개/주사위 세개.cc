#include <iostream>

using namespace std;

int main()
{
	int first, second, third;
	cin >> first >> second >> third;
	
	if (first == second && first == third)
		cout << 10000 + first * 1000;
	else if (first == second || first == third)
		cout << 1000 + first * 100;
	else if (second == third)
		cout << 1000 + second * 100;
	else
	{
		int max = first;
		if (max < second) max = second;
		if (max < third) max = third;
		cout << max * 100;
	}
}