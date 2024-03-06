#include <algorithm>
#include <iostream>
using namespace std;

int N;
int input[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> input[i];

	sort(&input[0], &input[N], greater<int>());

	for (int i = 0; i < N; i++)
		cout << input[i] << '\n';
}