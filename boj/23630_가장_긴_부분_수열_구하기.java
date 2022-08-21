import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int n;
    static int[] a, count;
    
    public static void main(String[] args) throws IOException {
        
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        
        count = new int[1000001];
        
        for (int i = 0; i < n; i++) {
            int bit = 1;
            while (bit < 1000000) {
                if ((a[i] & bit) > 0) {
                    count[bit]++;
                }
                bit <<= 1;
            }
        }
        
        System.out.print(Arrays.stream(count).max().getAsInt());
    }
}