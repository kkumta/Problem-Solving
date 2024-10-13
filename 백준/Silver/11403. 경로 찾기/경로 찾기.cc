#include <bits/stdc++.h>
using namespace std;

int N;
bool dist[100][100];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> dist[i][j];
			
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (dist[j][i] && dist[i][k]) dist[j][k] = true;
				
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}