import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, s, m;
    static int[] v;
    static boolean[][] d;
    
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        v = new int[n];
        d = new boolean[n][m + 1];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(st.nextToken());
        }
        
        if (s + v[0] <= m) { // 0번째 곡의 볼륨 + v[0]이 m보다 작거나 m과 같을 경우
            d[0][s + v[0]] = true;
        }
        if (s - v[0] >= 0) { // 0번째 곡의 볼륨 - v[0]이 0보다 크거나 0과 같을 경우
            d[0][s - v[0]] = true;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (d[i - 1][j]) { // 직전 곡이 해당 볼륨에서 연주됐는가?
                    if (j + v[i] <= m) { // 볼륨을 키워 이번 곡을 연주할 수 있는가?
                        d[i][j + v[i]] = true;
                    }
                    if (j - v[i] >= 0) { // 볼륨을 줄여 이번 곡을 연주할 수 있는가?
                        d[i][j - v[i]] = true;
                    }
                }
            }
        }
        
        for (int i = m; i >= 0; i--) {
            if (d[n - 1][i]) { // 마지막 곡의 볼륨이 유효하다면 그 값을 출력
                System.out.print(i);
                return;
            }
        }
        
        System.out.print(-1); // 마지막 곡을 연주할 수 없는 경우 -1 출력
    }
}