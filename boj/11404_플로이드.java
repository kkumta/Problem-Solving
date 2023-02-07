import java.util.*;
import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static int n, m;
    static long[][] d;
    static final long MAX = 100000 * 99 + 1; // 각 간선의 최대 비용 * 간선의 최대 개수까지 계산 시 활용되므로, 해당 값에 +1한 값을 MAX로 사용한다. 
    
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        d = new long[n + 1][n + 1];
        m = Integer.parseInt(br.readLine());
        for (int i = 1; i <= n; i++) {
            Arrays.fill(d[i], MAX);
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            d[a][b] =
                d[a][b] > c ? c : d[a][b]; // 기존의 d[a][b]가 새로운 비용보다 크면, d[a][b]를 새로운 비용으로 수정한다.
        }
        
        // 출발 지점 == 도착 지점일 경우는 비용을 0으로 초기화해준다.
        for (int i = 1; i <= n; i++) {
            d[i][i] = 0;
        }
        
        // 플로이드 알고리즘을 통해 모든 정점 to 모든 정점의 최단 경로를 구한다.
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    d[i][j] = d[i][j] > d[i][k] + d[k][j] ? d[i][k] + d[k][j] : d[i][j];
                }
            }
        }
        
        // 구한 최단 거리를 출력한다.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] == MAX) {
                    sb.append(0);
                } else {
                    sb.append(d[i][j]);
                }
                sb.append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }
}