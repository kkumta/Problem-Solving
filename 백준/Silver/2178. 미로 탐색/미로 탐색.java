import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    
    static class Coordinate {
        
        int row, col;
        
        public Coordinate(int row, int col) {
            this.row = row;
            this.col = col;
        }
        
        @Override
        public boolean equals(Object obj) {
            Coordinate o = (Coordinate) obj;
            
            if (this.row == o.row && this.col == o.col) {
                return true;
            }
            
            return false;
        }
    }
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int[][] dxy = new int[][]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    static int n, m;
    static int[][] maze, cnt;
    static Queue<Coordinate> queue = new ArrayDeque<>();
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        maze = new int[n][m];
        cnt = new int[n][m];
        
        for (int i = 0; i < n; i++) {
            String row = br.readLine();
            for (int j = 0; j < m; j++) {
                maze[i][j] = row.charAt(j) - '0';
            }
        }
        
        queue.add(new Coordinate(0, 0));
        cnt[0][0] = 1;
        bfs();
        
        System.out.print(cnt[n - 1][m - 1]);
    }
    
    private static void bfs() {
        while (!queue.isEmpty()) {
            Coordinate curPos = queue.poll();
            for (int i = 0; i < 4; i++) {
                Coordinate nextPos = new Coordinate(curPos.row + dxy[i][0], curPos.col + dxy[i][1]);
                if (nextPos.row < 0 || nextPos.row >= n || nextPos.col < 0 || nextPos.col >= m) {
                    continue;
                }
                if (maze[nextPos.row][nextPos.col] == 0) {
                    continue;
                }
                if (cnt[nextPos.row][nextPos.col] > 0) {
                    continue;
                }
                
                queue.add(nextPos);
                cnt[nextPos.row][nextPos.col] = cnt[curPos.row][curPos.col] + 1;
            }
        }
    }
}