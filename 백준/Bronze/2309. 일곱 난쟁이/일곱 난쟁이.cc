#include <bits/stdc++.h>
using namespace std;

int arr[9];

int main()
{
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
		
	sort(arr, arr + 9);	
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int sum = 0;
			for (int k = 0; k < 9; k++)
			{
				if (k == i || k == j) continue;
				sum += arr[k];
			}
			if (sum == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j) continue;
					cout << arr[k] << '\n';
				}
				return 0;
			}	
		}	
	}
}