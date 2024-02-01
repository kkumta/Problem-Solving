#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		for (int j = 0; j < 4; j++)
		{
			int input;
			cin >> input;
			if (input == 0) count++;
		}

		if (count == 0) cout << 'E' << endl;
		else if (count == 1) cout << 'A' << endl;
		else if (count == 2) cout << 'B' << endl;
		else if (count == 3) cout << 'C' << endl;
		else cout << 'D' << endl;
	}
}