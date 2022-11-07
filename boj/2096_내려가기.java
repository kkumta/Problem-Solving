import java.io.*;
import java.util.StringTokenizer;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n;
    static int[][] board, max, min;
    
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        board = new int[n][3];
        max = new int[n][3];
        min = new int[n][3];
        
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        for (int i = 0; i < 3; i++) {
            max[0][i] = board[0][i];
            min[0][i] = board[0][i];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                max[i][j] = max[i - 1][1];
                if (j != 2 && max[i - 1][0] > max[i][j]) {
                    max[i][j] = max[i - 1][0];
                }
                if (j != 0 && max[i - 1][2] > max[i][j]) {
                    max[i][j] = max[i - 1][2];
                }
                max[i][j] += board[i][j];
                
                min[i][j] = min[i - 1][1];
                if (j != 2 && min[i - 1][0] < min[i][j]) {
                    min[i][j] = min[i - 1][0];
                }
                if (j != 0 && min[i - 1][2] < min[i][j]) {
                    min[i][j] = min[i - 1][2];
                }
                min[i][j] += board[i][j];
            }
        }
        
        sb.append(Math.max(max[n - 1][0], Math.max(max[n - 1][1], max[n - 1][2]))).append(" ");
        sb.append(Math.min(min[n - 1][0], Math.min(min[n - 1][1], min[n - 1][2])));
        System.out.print(sb.toString());
    }
}