import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int t, n, m;
    static int[][] d;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        d = new int[30][30];

        for (int i = 0; i < 30; i++) {
            d[i][0] = 1; // nC0 = 1
            d[i][i] = 1; // nCn = 1
            d[i][1] = i; // nC1 = n
        }

        for (int i = 2; i < 30; i++) {
            for (int j = 2; j < 30; j++) {
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
            }
        }

        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            sb.append(d[m][n] + "\n");
        }

        System.out.print(sb.toString());
    }
}