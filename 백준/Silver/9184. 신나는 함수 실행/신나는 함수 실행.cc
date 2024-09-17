#include <bits/stdc++.h>
using namespace std;

// -50 -> 0, 0 -> 50, 50 -> 100

int d[101][101][101];
int a, b, c;

int main()
{	
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			for (int k = 0; k <= 100; k++)
			{
				if (i <= 50 || j <= 50 || k <= 50)
					d[i][j][k] = 1;
				else if (i > 70 || j > 70 || k > 70)
					d[i][j][k] = 1048576;
				else if (i < j && j < k)
					d[i][j][k] = d[i][j][k - 1] + d[i][j - 1][k - 1] - d[i][j - 1][k];
				else
					d[i][j][k] = d[i - 1][j][k] + d[i - 1][j - 1][k] + d[i - 1][j][k - 1] - d[i - 1][j - 1][k - 1];			
			}
		}	
	}
	
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		a += 50; b += 50; c += 50;
		cout << d[a][b][c] << '\n';
	}
}