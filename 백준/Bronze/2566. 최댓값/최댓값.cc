#include <bits/stdc++.h>
using namespace std;

int tmp;
int ret[] = {0, 1, 1};

int main()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			cin >> tmp;
			if (tmp > ret[0])
			{
				ret[0] = tmp;
				ret[1] = i;
				ret[2] = j;
			}
		}
		
	cout << ret[0] << '\n' << ret[1] << ' ' << ret[2];
}