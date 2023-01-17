class Solution {
    
    public int solution(int m, int n, int[][] puddles) {
        boolean[][] map = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = false;
            }
        }
        for (int[] puddle : puddles) {
            map[puddle[0] - 1][puddle[1] - 1] = true;
        }
        
        int[][] d = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = 0;
            }
        }
        
        // 0행, 0열 초기화
        d[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (!map[i][0]) {
                d[i][0] = d[i - 1][0];
            }
        }
        for (int i = 1; i < n; i++) {
            if (!map[0][i]) {
                d[0][i] = d[0][i - 1];
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!map[i][j]) {
                    d[i][j] = (d[i - 1][j] + d[i][j - 1]) % 1000000007;
                }
            }
        }
        
        return d[m - 1][n - 1];
    }
}