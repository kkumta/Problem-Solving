#include <string>
#include <vector>
using namespace std;

int dist[100][100], rowSum[100], colSum[100], ret;

int solution(int n, vector<vector<int>> results) 
{
    for (vector<int> v : results)
        dist[v[0] - 1][v[1] - 1] = 1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dist[j][k] == 0 && dist[j][i] == 1 && dist[i][k] == 1)
                    dist[j][k] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j]) rowSum[i]++;
            if (dist[i][j]) colSum[j]++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (rowSum[i] + colSum[i] == n - 1) ret++;
    }
    
    return ret;
}