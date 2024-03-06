#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
tuple<int, int, string> input[100001];

int compare(tuple<int, int, string> a, tuple<int, int, string> b)
{
	if (get<1>(a) == get<1>(b))
		return get<0>(a) < get<0>(b);
	else
		return get<1>(a) < get<1>(b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		get<0>(input[i]) = i;
		cin >> get<1>(input[i]) >> get<2>(input[i]);
	}

	stable_sort(&input[0], &input[N], compare);

	for (int i = 0; i < N; i++)
		cout << get<1>(input[i]) << ' ' << get<2>(input[i]) << '\n';
}