import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[][] triangle;
    static int[][] d;
    
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        triangle = new int[n][];
        d = new int[n][];
        for (int i = 0; i < n; i++) {
            triangle[i] = new int[i + 1];
            d[i] = new int[i + 1];
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < triangle[i].length; j++) {
                triangle[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        d[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    d[i][j] = d[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    d[i][j] = d[i - 1][j - 1] + triangle[i][j];
                } else {
                    d[i][j] = Math.max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
                }
            }
        }
        
        System.out.print(Arrays.stream(d[n - 1]).max().getAsInt());
    }
}