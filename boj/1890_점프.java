import java.io.*;
import java.util.StringTokenizer;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[][] board;
    static long[][] d;
    
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        d = new long[n][n];
        
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        d[0][0] = 1;
        for (int i = 1; i < n; i++) { // 0행으로 이동하는 경우
            for (int j = 0; j < i; j++) {
                if (j + board[0][j] == i) {
                    d[0][i] += d[0][j];
                }
            }
        }
        
        for (int i = 1; i < n; i++) { // 0열로 이동하는 경우
            for (int j = 0; j < i; j++) {
                if (j + board[j][0] == i) {
                    d[i][0] += d[j][0];
                }
            }
        }
        
        for (int i = 1; i < n; i++) { // 구하고 싶은 행
            for (int j = 1; j < n; j++) { // 구하고 싶은 열
                for (int k = 0; k < j; k++) { // 구하기 위해 필요한 열 기준 memo 값 (행 고정)
                    if (k + board[i][k] == j) {
                        d[i][j] += d[i][k];
                    }
                }
                for (int k = 0; k < i; k++) { // 구하기 위해 필요한 행 기준 memo 값 (열 고정)
                    if (k + board[k][j] == i) {
                        d[i][j] += d[k][j];
                    }
                }
            }
        }
        
        System.out.print(d[n - 1][n - 1]);
    }
}