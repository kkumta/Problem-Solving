#include <iostream>
#include <vector>
using namespace std;

int FindRequiredCount(int begin, int end, int w)
{
	if (end < begin)
		return 0;

	int result = (end - begin + 1) / (w * 2 + 1);
	if ((end - begin + 1) % (w * 2 + 1) != 0)
		result++;

	return result;
}

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	vector<pair<int, int>> sections(0);
	sections.push_back(make_pair(1, stations[0] - w - 1));
	if (stations.size() > 0 && stations[stations.size() - 1] < n - w)
		sections.push_back(make_pair(stations[stations.size() - 1] + w + 1, n));
	for (int i = 0; i < stations.size() - 1; i++)
		sections.push_back(make_pair(stations[i] + w + 1, stations[i + 1] - w - 1));

	for (vector<pair<int, int>>::iterator iter = sections.begin(); iter != sections.end(); iter++)
		answer += FindRequiredCount(iter->first, iter->second, w);

	return answer;
}