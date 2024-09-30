#include <bits/stdc++.h>
using namespace std;

int N;
int L[20], J[20], d[100];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	for (int i = 0; i < N; i++) cin >> J[i];
	
	for (int i = 0; i < N; i++)
	{
		int a = L[i];
		int b = J[i];
		// 각각의 사람에게 최대 1번만 말할 수 있으므로 오른쪽에서 왼쪽으로 
		for (int j = 99; j >= a; j--)
			d[j] = max(d[j], d[j - a] + b);
	}
	
	cout << d[99];
}