import static java.lang.Integer.*;

import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
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
    
    static int n, m, ans = MAX_VALUE;
    static int[][] map; // 0: 빈 칸, 1: 벽, 2: 바이러스
    static int[][] time;
    static List<Coordinate> allVirus = new ArrayList<>();
    static List<Coordinate> selectedVirus = new ArrayList<>();
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        n = parseInt(st.nextToken());
        m = parseInt(st.nextToken());
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = parseInt(st.nextToken());
                if (map[i][j] == 2) {
                    allVirus.add(new Coordinate(i, j));
                }
            }
        }
        
        // 0. 모든 칸의 시간 -1로 초기화
        initTime();
        
        // 1. 활성 바이러스가 놓일 칸 지정
        setVirus(0, -1);
        
        if (ans == MAX_VALUE) {
            System.out.print(-1);
        } else {
            System.out.print(ans);
        }
    }
    
    
    private static void setVirus(int k, int lastIdx) {
        if (k == m) { // race condition
            Queue<Coordinate> selectedVirusQueue = new ArrayDeque<>();
            for (Coordinate virus : selectedVirus) {
                time[virus.row][virus.col] = 0;
                selectedVirusQueue.add(virus);
            }
            bfs(selectedVirusQueue); // 2. 각 칸에 도달하는 시간 구하기
            findMinTime(); // 3. 가장 빠르게 모든 칸에 도달할 때 걸리는 시간 구하기
            for (Coordinate virus : selectedVirus) {
                selectedVirusQueue.add(virus);
            }
            initTime(); // 4. 모든 칸의 시간 다시 -1로 초기화
        }
        
        for (int i = lastIdx + 1; i < allVirus.size(); i++) {
            selectedVirus.add(allVirus.get(i));
            setVirus(k + 1, i);
            selectedVirus.remove(allVirus.get(i));
        }
    }
    
    private static void findMinTime() {
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 0) {
                    if (time[i][j] == -1) { // 도달하지 못한 곳이 1곳이라도 존재하는 경우
                        return;
                    }
                    if (time[i][j] > max) { // 처음에 빈칸이었던 칸까지 바이러스가 가는 데 걸리는 시간
                        max = time[i][j];
                    }
                }
            }
        }
        if (max < ans) {
            ans = max;
        }
    }
    
    private static void bfs(Queue<Coordinate> queue) {
        
        while (!queue.isEmpty()) {
            Coordinate curPos = queue.poll();
            for (int i = 0; i < 4; i++) {
                Coordinate nextPos = new Coordinate(curPos.row + dxy[i][0], curPos.col + dxy[i][1]);
                if (nextPos.row < 0 || nextPos.row >= n || nextPos.col < 0
                    || nextPos.col >= n) { // 지도에 없는 위치
                    continue;
                }
                
                if (map[nextPos.row][nextPos.col] != 1
                    && time[nextPos.row][nextPos.col] == -1) { // 벽이 아니고, 이미 방문한 위치도 아니다.
                    time[nextPos.row][nextPos.col] =
                        time[curPos.row][curPos.col] + 1; // 방문 체크, 시간 체크
                    queue.add(nextPos);
                }
            }
        }
    }
    
    private static void initTime() {
        time = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(time[i], -1);
        }
    }
}