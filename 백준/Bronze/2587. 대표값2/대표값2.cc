#include <iostream>

using namespace std;

int main()
{
	int input[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> input[i];
		sum += input[i];
	}

	for (int i = 0; i < 4; i++)
	{
		int min = input[i];
		int pos = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (input[j] < min)
			{
				min = input[j];
				pos = j;
			}
		}

		int temp = input[i];
		input[i] = input[pos];
		input[pos] = temp;
	}

	cout << sum / 5 << '\n' << input[2];
}