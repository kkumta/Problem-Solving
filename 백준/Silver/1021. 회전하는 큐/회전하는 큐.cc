#include <deque>
#include <iostream>
using namespace std;

int n, m, ans;
deque<int> dq1, dq2;

int main()
{
	// 입력
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dq1.push_back(i);


	for (int i = 0; i < m; i++)
	{
		int num, leftCnt = 0, rightCnt = 1;
		cin >> num;

		// 왼쪽으로 이동시킬 때 드는 연산의 최솟값
		while (true)
		{
			if (dq1.front() == num) break;
			leftCnt++;
			dq2.push_back(dq1.front()); dq1.pop_front();
		}

		// 원상 복구
		while (!dq2.empty())
		{
			dq1.push_front(dq2.back()); dq2.pop_back();
		}

		// 오른쪽으로 이동시킬 때 드는 연산의 최솟값
		while (true)
		{
			if (dq1.back() == num) break;
			rightCnt++;
			dq2.push_back(dq1.back()); dq1.pop_back();
		}

		// 원상 복구
		while (!dq2.empty())
		{
			dq1.push_back(dq2.back()); dq2.pop_back();
		}

		// 연산의 최솟값을 비교해서 더 나은 연산 적용하기
		if (leftCnt < rightCnt)
		{
			while (true)
			{
				if (dq1.front() == num)
				{
					dq1.pop_front();
					break;
				}
				dq1.push_back(dq1.front()); dq1.pop_front();
			}
			ans += leftCnt;
		}
		else
		{
			while (true)
			{
				if (dq1.front() == num)
				{
					dq1.pop_front();
					break;
				}
				dq1.push_front(dq1.back()); dq1.pop_back();
			}
			ans += rightCnt;
		}
	}

	cout << ans;
}