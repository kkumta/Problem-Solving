import static java.lang.Integer.*;

import java.io.*;
import java.util.*;

public class Main {
    
    static public class Pair {
        
        int up, down;
        
        public Pair(int up, int down) {
            this.up = up;
            this.down = down;
        }
    }
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] num;
    static Pair[] d;
    static int n;
    
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        n = parseInt(br.readLine());
        num = new int[n];
        d = new Pair[n];
        st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        
        for (int i = 0; i < n; i++) {
            d[i] = new Pair(1, 1);
        }
        
        // 증가하는 경우
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (num[i] > num[j] && d[i].up < d[j].up + 1) {
                    d[i].up = d[j].up + 1;
                }
            }
        }
        
        // 감소하는 경우
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (num[i] > num[j] && d[i].down < d[j].down + 1) {
                    d[i].down = d[j].down + 1;
                }
            }
        }
        
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (d[i].up + d[i].down > ans) {
                ans = d[i].up + d[i].down;
            }
        }
        
        System.out.print(ans - 1);
    }
}