#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
	int ans = 0;

	for (int i = 1; i < board.size(); i++)
	{
		for (int j = 1; j < board[0].size(); j++)
		{
			if (board[i][j] == 0)
				continue;

			board[i][j] = min(min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]) + 1;
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (ans < board[i][j])
				ans = board[i][j];
		}
	}

	return ans * ans;
}