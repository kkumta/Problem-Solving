import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] num;
    static long[][] d;
    
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        num = new int[n];
        d = new long[n][21];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        
        d[0][num[0]] = 1;
        for (int i = 1; i < n; i++) { // 이번 숫자의 index
            for (int j = 0; j <= 20; j++) { // 직전에 만든 수
                if (d[i - 1][j] > 0) {
                    if (j + num[i] <= 20) {
                        d[i][j + num[i]] += d[i - 1][j];
                    }
                    if (j - num[i] >= 0) {
                        d[i][j - num[i]] += d[i - 1][j];
                    }
                }
            }
        }
        
        System.out.print(d[n - 2][num[n - 1]]);
    }
}