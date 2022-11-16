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
    
    static int[] dx = new int[]{-1, 0, 1, 0};
    static int[] dy = new int[]{0, 1, 0, -1};
    
    static int r, c;
    static char[][] map;
    static Queue<Coordinate> queue = new ArrayDeque<>();
    static int[][] hedgehog; // 고슴도치가 해당 위치까지 도달하는 데 걸리는 시간
    static int[][] water; // 물이 차는 시간
    static boolean[][] waterVisited, hedgehogVisited;
    static Coordinate start, end;
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        map = new char[r][c];
        hedgehog = new int[r][c];
        water = new int[r][c];
        waterVisited = new boolean[r][c];
        hedgehogVisited = new boolean[r][c];
        
        for (int i = 0; i < r; i++) {
            String str = br.readLine();
            for (int j = 0; j < c; j++) {
                map[i][j] = str.charAt(j);
                if (map[i][j] == 'S') {
                    start = new Coordinate(i, j);
                    hedgehogVisited[i][j] = true;
                } else if (map[i][j] == 'D') {
                    end = new Coordinate(i, j);
                } else if (map[i][j] == '*') {
                    queue.add(new Coordinate(i, j));
                    waterVisited[i][j] = true;
                }
            }
        }
        
        // 물 채우기
        waterBfs();
        
        // 고슴도치 이동시키기
        queue.add(start);
        hedgehogBfs();
        
        // 답 출력
        if (hedgehog[end.row][end.col] == 0) {
            System.out.print("KAKTUS");
        } else {
            System.out.print(hedgehog[end.row][end.col]);
        }
    }
    
    private static void waterBfs() {
        while (!queue.isEmpty()) {
            Coordinate curPos = queue.poll();
            for (int i = 0; i < 4; i++) {
                Coordinate nextPos = new Coordinate(curPos.row + dy[i], curPos.col + dx[i]);
                
                if (nextPos.col < 0 || nextPos.row < 0 || nextPos.col >= c || nextPos.row >= r) {
                    continue;
                }
                if (map[nextPos.row][nextPos.col] == 'X' || map[nextPos.row][nextPos.col] == 'D') {
                    continue;
                }
                if (waterVisited[nextPos.row][nextPos.col]) {
                    continue;
                }
                
                queue.add(nextPos);
                water[nextPos.row][nextPos.col] = water[curPos.row][curPos.col] + 1;
                waterVisited[nextPos.row][nextPos.col] = true;
            }
        }
    }
    
    private static void hedgehogBfs() {
        while (!queue.isEmpty()) {
            Coordinate curPos = queue.poll();
            for (int i = 0; i < 4; i++) {
                Coordinate nextPos = new Coordinate(curPos.row + dy[i], curPos.col + dx[i]);
                
                if (nextPos.col < 0 || nextPos.row < 0 || nextPos.col >= c || nextPos.row >= r) {
                    continue;
                }
                if (map[nextPos.row][nextPos.col] == 'X') {
                    continue;
                }
                if (hedgehogVisited[nextPos.row][nextPos.col]) {
                    continue;
                }
                // 물이 차있는 경우 예외처리
                if (waterVisited[nextPos.row][nextPos.col]
                    && hedgehog[curPos.row][curPos.col] + 1 >= water[nextPos.row][nextPos.col]) {
                    continue;
                }
                
                queue.add(nextPos);
                hedgehog[nextPos.row][nextPos.col] = hedgehog[curPos.row][curPos.col] + 1;
                hedgehogVisited[nextPos.row][nextPos.col] = true;
            }
        }
    }
}