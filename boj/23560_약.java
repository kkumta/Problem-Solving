import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] d = new int[n];
        d[0] = 2;
        for (int i = 1; i < n; i++) {
            d[i] = d[i - 1] * 3;
        }
        
        System.out.print(d[n - 1]);
    }
}