#include <tuple>
#include <queue>
#include <iostream>
using namespace std;

int A, B, C, movingAmount;
tuple<int, int, int> curAmount, nextAmount;
bool check[201][201][201];

void BFS()
{
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, C));
	check[0][0][C] = true;

	while (!q.empty())
	{
		// A가 0인 경우 check 배열에 기록
		curAmount = q.front(); q.pop();
		if (get<0>(curAmount) == 0 && !check[get<0>(curAmount)][get<1>(curAmount)][get<2>(curAmount)])
			check[get<0>(curAmount)][get<1>(curAmount)][get<2>(curAmount)] = true;

		// 시뮬레이션(A -> B)
		movingAmount = min(get<0>(curAmount), B - get<1>(curAmount));
		nextAmount = make_tuple(get<0>(curAmount) - movingAmount, get<1>(curAmount) + movingAmount, get<2>(curAmount));
		if (!check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)])
		{
			check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)] = true;
			q.push(nextAmount);
		}

		// 시뮬레이션(A -> C)
		movingAmount = min(get<0>(curAmount), C - get<2>(curAmount));
		nextAmount = make_tuple(get<0>(curAmount) - movingAmount, get<1>(curAmount), get<2>(curAmount) + movingAmount);
		if (!check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)])
		{
			check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)] = true;
			q.push(nextAmount);
		}

		// 시뮬레이션(B -> A)
		movingAmount = min(A - get<0>(curAmount), get<1>(curAmount));
		nextAmount = make_tuple(get<0>(curAmount) + movingAmount, get<1>(curAmount) - movingAmount, get<2>(curAmount));
		if (!check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)])
		{
			check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)] = true;
			q.push(nextAmount);
		}

		// 시뮬레이션(B -> C)
		movingAmount = min(get<1>(curAmount), C - get<2>(curAmount));
		nextAmount = make_tuple(get<0>(curAmount), get<1>(curAmount) - movingAmount, get<2>(curAmount) + movingAmount);
		if (!check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)])
		{
			check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)] = true;
			q.push(nextAmount);
		}

		// 시뮬레이션(C -> A)
		movingAmount = min(get<2>(curAmount), A - get<0>(curAmount));
		nextAmount = make_tuple(get<0>(curAmount) + movingAmount, get<1>(curAmount), get<2>(curAmount) - movingAmount);
		if (!check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)])
		{
			check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)] = true;
			q.push(nextAmount);
		}

		// 시뮬레이션(C -> B)
		movingAmount = min(get<2>(curAmount), B - get<1>(curAmount));
		nextAmount = make_tuple(get<0>(curAmount), get<1>(curAmount) + movingAmount, get<2>(curAmount) - movingAmount);
		if (!check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)])
		{
			check[get<0>(nextAmount)][get<1>(nextAmount)][get<2>(nextAmount)] = true;
			q.push(nextAmount);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;

	BFS();

	for (int i = 0; i <= C; i++)
		if (check[0][C - i][i]) cout << i << ' ';
}