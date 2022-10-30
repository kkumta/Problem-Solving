import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int t, n;
    static int[][] d;
    static int divide = 1000000009;
    
    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        d = new int[100001][4]; // 모든 수의 합이 1~100000가 되면서 1~3중 하나의 수가 마지막으로 더해지는, 경우의 수
        d[1][1] = 1;
        d[2][2] = 1;
        d[3][1] = 1;
        d[3][2] = 1;
        d[3][3] = 1;
        
        for (int i = 4; i <= 100000; i++) {
            for (int j = 1; j <= 3; j++) {
                d[i][j] = d[i - j][(j + 3) % 3 + 1] + d[i - j][(j + 1) % 3 + 1];
                d[i][j] %= divide;
            }
        }
        
        for (int k = 0; k < t; k++) {
            n = Integer.parseInt(br.readLine());
            sb.append((((d[n][1] + d[n][2]) % divide) + d[n][3]) % divide).append("\n");
        }
        
        System.out.print(sb.toString());
    }
}