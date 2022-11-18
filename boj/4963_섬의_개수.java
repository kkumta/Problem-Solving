import static java.lang.Integer.*;

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
    static StringBuilder sb = new StringBuilder();
    
    static int[][] dxy = new int[][]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1},
        {1, 1}};
    
    static int h, w;
    static int[][] map;
    static boolean[][] isVisited;
    
    public static void main(String[] args) throws IOException {
        
        while (true) {
            st = new StringTokenizer(br.readLine());
            w = parseInt(st.nextToken());
            if (w == 0) {
                System.out.print(sb.toString());
                return;
            }
            h = parseInt(st.nextToken());
            map = new int[h][w];
            isVisited = new boolean[h][w];
            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++) {
                    map[i][j] = parseInt(st.nextToken());
                }
            }
            
            int cnt = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (map[i][j] == 1 && !isVisited[i][j]) { // 방문하지 않은 땅에서 섬 시작
                        bfs(new Coordinate(i, j));
                        cnt++;
                    }
                }
            }
            
            sb.append(cnt).append("\n");
        }
    }
    
    private static void bfs(Coordinate c) {
        Queue<Coordinate> queue = new ArrayDeque<>();
        queue.add(c);
        isVisited[c.row][c.col] = true;
        while (!queue.isEmpty()) {
            Coordinate curPos = queue.poll();
            for (int i = 0; i < 8; i++) {
                Coordinate nextPos = new Coordinate(curPos.row + dxy[i][0], curPos.col + dxy[i][1]);
                if (nextPos.row < 0 || nextPos.row >= h || nextPos.col < 0
                    || nextPos.col >= w) { // 지도에 없는 위치
                    continue;
                }
                if (map[nextPos.row][nextPos.col] == 0) { // 바다
                    continue;
                }
                if (isVisited[nextPos.row][nextPos.col]) { // 이미 방문한 땅
                    continue;
                }
                
                isVisited[nextPos.row][nextPos.col] = true;
                queue.add(nextPos);
            }
        }
    }
}