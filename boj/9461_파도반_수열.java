import static java.lang.Integer.*;

import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int t;
    static long[] d = new long[101];
    
    public static void main(String[] args) throws IOException {
        
        d[1] = 1;
        d[2] = 1;
        d[3] = 1;
        
        for (int i = 4; i < 101; i++) {
            d[i] = d[i - 2] + d[i - 3];
        }
        
        // 입력
        t = parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            sb.append(d[parseInt(br.readLine())]).append("\n");
        }
        
        System.out.print(sb.toString());
    }
}