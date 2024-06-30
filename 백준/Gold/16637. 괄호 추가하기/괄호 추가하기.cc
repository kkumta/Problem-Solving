#include <bits/stdc++.h>
using namespace std;

string str;
int N, ret = -(2^31);
vector<int> nums;
vector<char> opers;

int calc(int oper, int num1, int num2)
{
	if (oper == '+')
		return num1 + num2;
	else if (oper == '-')
		return num1 - num2;
	else if (oper == '*')
		return num1 * num2;
}

void go(int idx, int sum)
{
	if (idx == nums.size() - 1)
	{
		ret = max(ret, sum);
		return;
	}
	// 원래 연산 순서대로 계산한다. 
	go(idx + 1, calc(opers[idx], sum, nums[idx + 1]));
	// 괄호: 한 칸 오른쪽에 있는 수와 두 칸 오른쪽에 있는 수를 한 칸 오른쪽에 있는 연산자로 계산한다. 
	if (idx < nums.size() - 2)
	{
		int tmp = calc(opers[idx + 1], nums[idx + 1], nums[idx + 2]);
		go(idx + 2, calc(opers[idx], sum, tmp));
	}
}

int main()
{
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		char tmp = str[i];
		if (tmp >= '0' && tmp <= '9')
			nums.push_back(tmp - '0');
		else
			opers.push_back(tmp);
	}
	
	go(0, nums[0]);
	
	cout << ret;
}