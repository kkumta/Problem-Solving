#include <iostream>
using namespace std;

int n, x;
int arr[100001];
bool isExist[2000000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
		isExist[input] = true;
	}
	cin >> x;

	// 합이 x가 되는 쌍 구하기
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (x > arr[i] && isExist[x - arr[i]]) cnt++;

	cout << cnt / 2;
}