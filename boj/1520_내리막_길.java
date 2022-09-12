import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int m, n;
    static int[][] map, d;
    static int[][] dxy = new int[][]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        map = new int[m][n];
        d = new int[m][n];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                d[i][j] = -1;
            }
        }
        
        System.out.print(dfs(0, 0));
    }
    
    private static int dfs(int row, int cal) {
        
        if (row == m - 1 && cal == n - 1) {
            return 1;
        }
        if (d[row][cal] != -1) {
            return d[row][cal];
        }
        
        d[row][cal] = 0;
        for (int i = 0; i < 4; i++) {
            int nextRow = row + dxy[i][0];
            int nextCal = cal + dxy[i][1];
            if (nextRow < 0 || nextCal < 0 || nextRow >= m || nextCal >= n) {
                continue;
            }
            if (map[nextRow][nextCal] >= map[row][cal]) {
                continue;
            }
            
            d[row][cal] += dfs(nextRow, nextCal);
        }
        
        return d[row][cal];
    }
}