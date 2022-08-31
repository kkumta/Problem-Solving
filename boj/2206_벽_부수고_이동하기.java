import java.io.*;
import java.util.*;

public class Main {
    
    private static class MapInfo {
        
        int row, cal;
        boolean isBroken;
        
        public MapInfo(int row, int cal, boolean isBroken) {
            this.row = row;
            this.cal = cal;
            this.isBroken = isBroken;
        }
    }
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int[][] map;
    static int[][][] route;
    static Queue<MapInfo> queue = new ArrayDeque<>();
    static int[][] d = new int[][]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        route = new int[n][m][2];
        
        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = input.charAt(j) - '0';
            }
        }
        
        queue.add(new MapInfo(0, 0, false));
        route[0][0][0] = 1;
        while (!queue.isEmpty()) {
            MapInfo curInfo = queue.poll();
            if (curInfo.row == n - 1 && curInfo.cal == m - 1) {
                if (curInfo.isBroken) {
                    System.out.print(route[n - 1][m - 1][1]);
                } else {
                    System.out.print(route[n - 1][m - 1][0]);
                }
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nextRow = curInfo.row + d[i][0];
                int nextCal = curInfo.cal + d[i][1];
                
                if (nextRow < 0 || nextRow >= n || nextCal < 0
                    || nextCal >= m) { // 경로가 map을 벗어나는 경우
                    continue;
                }
                
                if (curInfo.isBroken && route[nextRow][nextCal][1] > 0) { // 이미 방문한 경로인 경우(벽을 부순 경우)
                    continue;
                }
                
                if (route[nextRow][nextCal][0] > 0) { // 이미 방문한 경로인 경우(벽을 부수지 않은 경우)
                    continue;
                }
                
                if (map[nextRow][nextCal] == 1) { // 다음 경로가 벽인 경우
                    if (curInfo.isBroken) { // 이미 벽을 1번 부순 경우
                        continue;
                    }
                    route[nextRow][nextCal][1] =
                        route[curInfo.row][curInfo.cal][0] + 1; // 아직 벽을 안 부쉈고 새롭게 부수는 경우
                    queue.add(new MapInfo(nextRow, nextCal, true));
                } else { // 다음 경로가 벽이 아닌 경우
                    if (curInfo.isBroken) { // 이미 벽을 1번 부순 경우
                        route[nextRow][nextCal][1] = route[curInfo.row][curInfo.cal][1] + 1;
                        queue.add(new MapInfo(nextRow, nextCal, true));
                    } else { // 아직 벽을 안 부순 경우
                        route[nextRow][nextCal][0] = route[curInfo.row][curInfo.cal][0] + 1;
                        queue.add(new MapInfo(nextRow, nextCal, false));
                    }
                }
            }
        }
        
        System.out.print(-1);
    }
}