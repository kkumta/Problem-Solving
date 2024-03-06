#include <algorithm>
#include <iostream>
using namespace std;

int N;
pair<int, int> input[100001];

int compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> input[i].first >> input[i].second;

	sort(&input[0], &input[N], compare);

	for (int i = 0; i < N; i++)
		cout << input[i].first << ' ' << input[i].second << '\n';
}