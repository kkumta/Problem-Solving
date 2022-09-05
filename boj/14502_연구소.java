import java.io.*;
import java.util.*;

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
    
    static int n, m, max = 0; // max: 바이러스가 닿지 않는 공간의 수의 최대
    static int[][] map; // 벽이 설치되기 전 맵
    static int[][] changedMap; // 벽이 설치된 맵
    static List<Coordinate> virus = new ArrayList<>();
    
    static int[][] dxy = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 2) {
                    virus.add(new Coordinate(i, j));
                }
            }
        }
        
        makeCase(new ArrayList<>());
        System.out.print(max);
    }
    
    private static void makeCase(List<Coordinate> caseList) {
        if (caseList.size() == 3) {
            bfs(caseList);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0 && !caseList.contains(new Coordinate(i, j))) {
                    caseList.add(new Coordinate(i, j));
                    makeCase(caseList);
                    caseList.remove(new Coordinate(i, j));
                }
            }
        }
    }
    
    private static void bfs(List<Coordinate> caseList) {
        
        // changedMap 초기화
        changedMap = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                changedMap[i][j] = map[i][j];
            }
        }
        for (Coordinate wall : caseList) {
            changedMap[wall.row][wall.col] = 1;
        }
        
        // 바이러스의 위치를 큐에 넣고 바이러스를 퍼뜨릴 수 있는 공간에 모두 퍼뜨린다.
        Queue<Coordinate> queue = new ArrayDeque<>();
        for (Coordinate coordinate : virus) {
            queue.add(coordinate);
        }
        
        while (!queue.isEmpty()) {
            Coordinate cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                Coordinate next = new Coordinate(cur.row + dxy[i][0], cur.col + dxy[i][1]);
                if (next.row < 0 || next.col < 0 || next.row >= n || next.col >= m) {
                    continue;
                }
                if (changedMap[next.row][next.col] != 0) {
                    continue;
                }
                changedMap[next.row][next.col] = 2;
                queue.add(new Coordinate(next.row, next.col));
            }
        }
        
        // 바이러스를 다 퍼뜨린 후 바이러스가 퍼지지 않은 공간의 수를 완전탐색으로 구한다.
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (changedMap[i][j] == 0) {
                    cnt++;
                }
            }
        }
        
        if (cnt > max) {
            max = cnt;
        }
    }
}