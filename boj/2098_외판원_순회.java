import java.util.*;
import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int N;
    static int[][] weight, d;
    static final int INF = 1000000 * 16 + 1;
    
    public static void main(String[] args) throws IOException {
        
        N = Integer.parseInt(br.readLine());
        weight = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int temp = Integer.parseInt(st.nextToken());
                weight[i][j] = temp;
            }
        }
        d = new int[N][1 << N]; // 현재 방문한 도시, 지금까지 방문한 도시들 bit
        
        int ans = TSP(0, 1);
        System.out.print(ans);
    }
    
    // cur: 현재 방문한 도시, visited: 지금까지 방문한 도시들 bit
    private static int TSP(int cur, int visited) {
        if (d[cur][visited] != 0) { // 한 번 방문한 경로에 대한 값은 다시 기록하지 않는다
            return d[cur][visited];
        }
        
        // 이미 모든 마을을 방문한 경우
        if (visited == (1 << N) - 1) {
            if (weight[cur][0] == 0) { // 시작점으로 되돌아갈 수 없는 경우
                return INF;
            }
            return weight[cur][0]; // 시작점으로 되돌아갈 수 있는 경우
        }
        
        // 아직 방문하지 않은 마을을 순회한다
        d[cur][visited] = INF;
        for (int i = 0; i < N; i++) {
            // i번 마을을 이미 방문하지 않았고, i번 마을로 갈 수 있는 경우
            if ((visited & (1 << i)) != 0 || weight[cur][i] == 0) {
                continue;
            }
            d[cur][visited] = Math.min(d[cur][visited],
                                       TSP(i, visited | (1 << i)) + weight[cur][i]);
        }
        
        return d[cur][visited];
    }
}
